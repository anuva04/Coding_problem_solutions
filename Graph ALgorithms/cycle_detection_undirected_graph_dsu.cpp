#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rankSet;

void makeSet(int v){
    parent[v] = v;
    rankSet[v] = 1;
}

int findSet(int v){
    if(v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(rankSet[a] < rankSet[b]) swap(a,b);
        parent[b] = a;
        if(rankSet[a] == rankSet[b]) rankSet[a]++;
    }
}

bool hasCycleDisjointSet(vector<vector<int>>& graph){
    int numNodes = graph.size();
    parent.clear();
    rankSet.clear();
    parent.resize(numNodes);
    rankSet.resize(numNodes);
    for(int i=0; i<numNodes; i++){
        makeSet(i);
    }
    for(int u=0; u<numNodes; u++){
        for(auto v : graph[u]){
            int x = findSet(u);
            int y = findSet(v);
            if(x == y) return true;
            unionSet(u, v);
        }
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
    if(hasCycleDisjointSet(graph)) cout << "Graph has cycle" << endl;
    else cout << "Graph does not have cycle" << endl;
}