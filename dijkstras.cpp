#include <iostream>
#include<vector>
#include <queue>
#include<climits>
#include <set>
using namespace std;

int minimumDistanceNode(set<int> remainingNodes,vector<int> distanceFromStart){
    int minDistance=INT_MAX;
    set<int>::iterator it;
    it=remainingNodes.begin();
    int currentNodeCnt;
    int minDistanceNodeCnt;
    for(it=remainingNodes.begin();it!=remainingNodes.end();++it){
        currentNodeCnt=*it;
        if(minDistance>=distanceFromStart[currentNodeCnt]){
            minDistance=distanceFromStart[currentNodeCnt];
            minDistanceNodeCnt=currentNodeCnt;
        }
    }
    // cout<<"min distance node is :"<<minDistanceNodeCnt<<endl;
    return minDistanceNodeCnt;
}

int distanceBetweenNodes(int x,int y,vector<vector<pair<int,int> > > addressVector){
    vector<pair<int,int> > nodesConnected=addressVector[x];
    int size=nodesConnected.size();
    for(int i=0;i<size;i++){
        if(nodesConnected[i].first==y){
            return nodesConnected[i].second;
        }
    }
    return INT_MAX;

}

int main() {
    int t,n,m,s,x,y,r;
    set<int> remainingNodes;

    cin>>t;
    while(t--)
    {
        remainingNodes.clear();
        cin>>n>>m;
        vector< vector< pair<int,int> > > addressVector(n+1);
        vector<int> distanceFromStart(n+1,INT_MAX);
        for(int i=1;i<=n;i++){
            remainingNodes.insert(i);
        }

        while(m--)
        {
            cin>>x>>y>>r;
            vector<pair<int,int> > nodesConnected=addressVector[x];
            int size=nodesConnected.size();
            bool fl=false;
            for(int i=0;i<size;i++){
                if(nodesConnected[i].first==y){
                    if(nodesConnected[i].second>r){
                        fl=true;
                        addressVector[x][i].second=r;
                        vector<pair<int,int> > nodesConnectedToY=addressVector[y];
                        int size1=nodesConnectedToY.size();
                        for(int j=0;j<size1;j++){
                            if(nodesConnectedToY[i].first==x){
                                addressVector[y][i].second=r;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if(!fl)
            {

                addressVector[x].push_back(make_pair(y,r));
                addressVector[y].push_back(make_pair(x,r));
            }
        }
        cin>>s;
        distanceFromStart[s]=0;
        remainingNodes.erase(s);
        vector<pair<int,int> > nodesConnectedToS=addressVector[s];
        int vectorSize=nodesConnectedToS.size();
        // cout<<"Nodes connected of s"<<endl;
        for(int v=0;v<vectorSize;v++){
            distanceFromStart[nodesConnectedToS[v].first]=nodesConnectedToS[v].second;
        }
        // minimumDistanceNode(remainingNodes,distanceFromStart);
        int minDistanceNodeNum;
        while(!remainingNodes.empty()){
            minDistanceNodeNum=minimumDistanceNode(remainingNodes,distanceFromStart);
            int minDistance=distanceFromStart[minDistanceNodeNum];
            vector<pair<int,int> > nodesConnected=addressVector[minDistanceNodeNum];
            int size=nodesConnected.size();
            for(int i=0;i<size;i++){
                int nodeNum=nodesConnected[i].first;
                int distanceFromStartToNodeNum=minDistance+distanceBetweenNodes(minDistanceNodeNum,nodeNum,addressVector);
                if(distanceFromStartToNodeNum<distanceFromStart[nodeNum]){
                    distanceFromStart[nodeNum]=distanceFromStartToNodeNum;
                }
            }
            remainingNodes.erase(minDistanceNodeNum);

        }

         for(int i=1;i<=n;i++)
         {
            if(i!=s)
            {
                if(distanceFromStart[i]==INT_MAX){
                    cout<<"-1"<<" ";
                }
                else{
                cout<<distanceFromStart[i]<<" ";
            }
            }
         }

         cout<<endl;
    }
    return 0;
}
