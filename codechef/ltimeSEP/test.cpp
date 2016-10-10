/*input
1
5
1 2 3 4 5
1 2
1 3
2 4
2 5
*/
#include <iostream>
#include <map>
#include <queue>

#define MAX 100005
using namespace std
;std::vector<int> fc[MAX];
map<int, int> fc1;

int max(int a, int b,int c){
	int m1 = (a>b)?a:b;
	return (m1>c)?m1:c;
}

int main() {
    int t,n,u,v,c;
    int cost[MAX];
    int ori[MAX];
    queue<int> q;
    bool visited[MAX];
    cin>>t;
    while(t--){
        fc.clear();
        fc1.clear();
        q.empty();
        cin>>n;
        for(int i = 1;i <= n; i++){
        	cin>>c;
        	cost[i] = c;
        	ori[i] = c;
            // cin>>cost[i];

            visited[i] = false;
        }
        for(int i = 0; i < n-1; i++){
            cin>>u>>v;
            fc[v] = u;
            fc1[u] = v;
        }
        int node;
        for(int i = 2; i <=n ;i++){
            if(fc1[i] == 0){
            	// cout<<"for i :"<<i<<endl;
            	cost[fc[i]] = max(cost[i], cost[fc[i]], cost[i] xor ori[fc[i]]);
            	// cout<<" for :"<<i<<"cost["<<fc[i]<<"]:"<<cost[fc[i]]<<endl;
            	if(!visited[fc[i]] && fc[i] != 1){
            		// cout<<"pushed "<<fc[i]<<" ";
            		visited[fc[i]] = true;
            		q.push(fc[i]);
            	}
            	visited[i] = true;
        	}
         }
         while(!q.empty()){
         	node = q.front();
         	q.pop();
         	cost[fc[node]] = max(cost[node], cost[fc[node]], cost[node] xor ori[fc[node]]);
         	// cout<<"popped node is :"<<node<<" and parent :"<<fc[node]<<endl;
         	if(!visited[fc[node]]){
         		visited[fc[node]] = true;
         		q.push(fc[node]);
         	}
         	
         }

         for(int i = 1; i <= n; i++){
         	cout<<cost[i]<<endl;
         }

        
    }
	return 0;
}
