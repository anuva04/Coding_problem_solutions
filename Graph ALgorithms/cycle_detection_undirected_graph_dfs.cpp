#include <bits/stdc++.h>
using namespace std;

bool hasCycledfsUtil(vector<vector<int>>& graph, int u, set<int>& visited, int parent){
    visited.insert(u);
    for(auto nei : graph[u]){
        if(nei == parent) continue;
        if(visited.find(nei) != visited.end()) return true;
        bool flag = hasCycledfsUtil(graph, nei, visited, u);
        if(flag) return true;
    }
    return false;
}

bool hasCycledfs(vector<vector<int>>& graph){
    set<int> visited;
    for(int u=0; u<graph.size(); u++){
        if(visited.find(u) != visited.end()) continue;
        bool flag = hasCycledfsUtil(graph, u, visited, -1);
        if(flag) return true;
    }
    return false;
}

int main(){
    int numNodes; cin>>numNodes;
    int numEdges; cin>>numEdges;
    vector<vector<int>> graph(numNodes);
    while(numEdges--){
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
    }
    if(hasCycledfs(graph)) cout << "Graph has cycle" << endl;
    else cout << "Graph does not have cycle" << endl;
}