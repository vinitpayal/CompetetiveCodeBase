#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int main() {
    int t,n,m,s,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vetcor< vector<int> > addressVector(n+1);
        vector<int> distanceFromStart(n+1,-1);

        // vector<bool> isVisited(n+1,-1);
         queue<int> q;
        while(m--)
        {
            cin>>x>>y;
            addressVector[x].push_back(y);
        	addressVector[y].push_back(x);
        }
        cin>>s;

         int len=addressVector[s].size();

        if(len!=0){
            for(int v=0;v<len;v++){
                distanceFromStart[addressVector[s][v]]=6;
                  q.push(addressVector[s][v]);
        	  }
         }

         while(! q.empty())
         {
            int nodeNumber=q.front();
            int d=distanceFromStart[nodeNumber];
            vector<int> nodesConnectedToNode=addressVector[nodeNumber];
            int noOfNodes=nodesConnectedToNode.size();
            for(int i=0;i<noOfNodes;i++)
            {
                if(distanceFromStart[nodesConnectedToNode[i]]==-1)
                {
                    distanceFromStart[nodesConnectedToNode[i]]=(d+6);
                    q.push(nodesConnectedToNode[i]);
                }
                else
                {
                    if(distanceFromStart[nodesConnectedToNode[i]]>(d+6))
                    {
                        distanceFromStart[nodesConnectedToNode[i]]=(d+6);
                    }
                }
            }
            // cout<<" element from queue is :"<<q.front()<<" and distance is "<<distanceFromStart[q.front()]<<endl;
            q.pop();
         }

         for(int i=1;i<=n;i++)
         {
            if(i!=s)
            {
                cout<<"For "<<i<<"distance from start :"<<distanceFromStart[i]<<endl;
            }
         }

    }
	return 0;
}
