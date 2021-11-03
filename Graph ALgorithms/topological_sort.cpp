#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void topologicalSortUtil(vector<vector<int>>& graph, int node, stack<int>& topSort, set<int>& visited){
    visited.insert(node);
    for(int nei : graph[node]){
        if(visited.find(nei) != visited.end()) continue;
        topologicalSortUtil(graph, nei, topSort, visited);
    }
    topSort.push(node);
}

void topologicalSort(vector<vector<int>>& graph, int numNodes){
    stack<int> topSort;
    set<int> visited;
    for(int node=1; node<=numNodes; node++){
        if(visited.find(node) != visited.end()) continue;
        topologicalSortUtil(graph, node, topSort, visited);
    }
    while(!topSort.empty()){
        int node = topSort.top();
        topSort.pop();
        cout << node << " ";
    }
    cout << endl;
}

int main(){
    int numNodes; cin>>numNodes;
    int numEdges; cin>>numEdges;
    vector<vector<int>> graph(numNodes+1);
    for(int i=0; i<numEdges; i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
    }
    topologicalSort(graph, numNodes);
}