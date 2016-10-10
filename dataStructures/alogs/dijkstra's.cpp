#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int main() {
    int t,n,m,s,x,y,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector< vector< pair<int,int> > > addressVector(n+1);
        vector<int> distanceFromStart(n+1,-1);

        // vector<bool> isVisited(n+1,-1);
         queue<int> q;
        while(m--)
        {
            cin>>x>>y>>r;
            addressVector[x].push_back(make_pair(y,r));
        	addressVector[y].push_back(make_pair(x,r));
        }
        cin>>s;

         int len=addressVector[s].size();

         cout<<"Length is :"<<len<<endl;

        // if(len!=0){
        //     for(int v=0;v<len;v++){
        //         distanceFromStart[addressVector[s][v].first]=addressVector[s][v].second;
        //           q.push(addressVector[s][v].first);
        // 	  }
        //  }

        //  while(! q.empty())
        //  {
        //     int nodeNumber=q.front();
        //     int d=distanceFromStart[nodeNumber];
        //     vector<int> nodesConnectedToNode=addressVector[nodeNumber];
        //     int noOfNodes=nodesConnectedToNode.size();
        //     for(int i=0;i<noOfNodes;i++)
        //     {
        //         if(distanceFromStart[nodesConnectedToNode[i].first]==-1)
        //         {
        //             distanceFromStart[nodesConnectedToNode[i].first]=(d+nodesConnectedToNode[i].second);
        //             q.push(nodesConnectedToNode[i].first);
        //         }
        //         else
        //         {
        //             if(distanceFromStart[nodesConnectedToNode[i].first]>(d+nodesConnectedToNode[i].second))
        //             {
        //                 distanceFromStart[nodesConnectedToNode[i]]=(d+nodesConnectedToNode[i].second);
        //             }
        //         }
        //     }
        //     // cout<<" element from queue is :"<<q.front()<<" and distance is "<<distanceFromStart[q.front()]<<endl;
        //     q.pop();
        //  }

        //  for(int i=1;i<=n;i++)
        //  {
        //     if(i!=s)
        //     {
        //         cout<<"For "<<i<<"distance from start :"<<distanceFromStart[i]<<endl;
        //     }
        //  }

    }
	return 0;
}
