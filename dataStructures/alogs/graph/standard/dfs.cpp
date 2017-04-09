#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

struct graph{
	int v;
	vector<int>* adl;
};

struct graph* createGraph(int nodeCount){
	struct graph* tempGraph = (struct graph*) malloc(sizeof(struct graph)); 

	tempGraph->v = nodeCount;
	
	//create an array of size nodeCount whose every element is a vector
	tempGraph->adl = (vector<int> *) malloc(nodeCount * sizeof(vector<int>));

	//every node is connected to self
	for(int i = 0; i < nodeCount; i++){
		tempGraph->adl[i].push_back(i);
	}
	return tempGraph;
}

void addEdge(struct graph* g, int s, int d){
	
	g->adl[s].push_back(d);
	g->adl[d].push_back(s); 
}

void printGraph(struct graph* g){
	int nodeCount = g->v;

	for(int i = 0; i < nodeCount; i++){
		cout<<"For node "<<i<<" Connected Nodes \n";

		vector<int> connectedNodes = g->adl[i];
		vector <int> :: iterator it;

		for(it = connectedNodes.begin(); it != connectedNodes.end(); ++it){
			cout<<*it<<"->";
		} 

		cout<<"\n";
	}
}

void dfs(struct graph* g, int n, bool* visited){
	if(!visited[n]){
		cout<<n<<",";
		visited[n] = true;

		vector<int>::iterator it;

		for(it = g->adl[n].begin(); it != g->adl[n].end(); ++it){
			if(!visited[*it]) dfs(g, *it, visited);
		}
	}
}

void bfs(struct graph* g, int startingNode, bool* visited){

	queue<int> q;

	q.push(startingNode);

	int currNode;

	while(!q.empty()){
		currNode = q.front();
		q.pop();

		if(!visited[currNode]){
			visited[currNode] = true;
			cout<<currNode<<",";

			vector<int> nodesConnectedToCurrNode = g->adl[currNode];

			vector<int>::iterator it;

			for(it = nodesConnectedToCurrNode.begin(); it != nodesConnectedToCurrNode.end(); ++it){
				if(!visited[*it]){
					q.push(*it);
				}
			}
		}
	}
}		

int main(){

	int graphCapacity = 5;

	struct graph* g = createGraph(graphCapacity);
	bool visited[graphCapacity] = {false}; 
	bool bfsVisited[graphCapacity] = {false};
	
	addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);

	printGraph(g);

	dfs(g, 2, visited);

	cout<<"\n bfs \n";

	bfs(g, 2, bfsVisited);
	return 0;
}