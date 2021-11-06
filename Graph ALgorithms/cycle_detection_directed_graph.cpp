#include <bits/stdc++.h>
using namespace std;

bool dfs(map<int, vector<int>>& graph, int curr_node, set<int>& not_visited, set<int>& visiting, set<int>& visited){
    not_visited.erase(curr_node);
    visiting.insert(curr_node);
    for(auto nei : graph[curr_node]){
        if(visited.find(nei) != visited.end()) continue;
        if(visiting.find(nei) != visiting.end()) return true;
        if(dfs(graph, nei, not_visited, visiting, visited)) return true;
    }
    visited.erase(curr_node);
    visited.insert(curr_node);
    return false;
}

bool hasCycle(map<int, vector<int>>& graph){
    set<int> not_visited, visiting, visited;
    for(auto node : graph) not_visited.insert(node.first);
    while(!not_visited.empty()){
        auto curr_node = *not_visited.begin();
        if(dfs(graph, curr_node, not_visited, visiting, visited)) return true;
    }
    return false;
}

int main(){
    map<int, vector<int>> graph;
    int numEdges; cin>>numEdges;
    while(numEdges--){
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
    }
    if(hasCycle(graph)) cout << "Graph has cycle" << endl;
    else cout << "Graph does not have cycle" << endl;
}