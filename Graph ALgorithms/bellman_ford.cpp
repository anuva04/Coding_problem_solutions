#include <bits/stdc++.h>
using namespace std;

void bellmanFordShortestPath(vector<vector<int>>& graph, vector<pair<int,int> >& edges, int numNodes, int src){
    map<int, int> v_dist;
    map<int, int> v_parent;
    for(int i=0; i<numNodes; i++){
        v_dist[i] = INT_MAX;
        v_parent[i] = i;
    }
    v_dist[src] = 0;
    for(int i=0; i<numNodes-1; i++){
        for(auto edge : edges){
            int u = edge.first;
            int v = edge.second;
            if(v_dist[u]+graph[u][v] < v_dist[v]){
                v_dist[v] = v_dist[u]+graph[u][v];
                v_parent[v] = u;
            }
        }
    }
    for(auto edge : edges){
        int u = edge.first;
        int v = edge.second;
        if(v_dist[u]+graph[u][v] < v_dist[v]){
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }
    for(auto ele : v_dist){
        cout << ele.first << " -> " << ele.second << endl;
    }
}

int main(){
    int numNodes; cin>>numNodes;
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, 0));
    int numEdges; cin>>numEdges;
    vector<pair<int,int> > edges;
    for(int i=0; i<numEdges; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u][v] = w;
        edges.push_back({u,v});
    }
    int src; cin>>src;
    bellmanFordShortestPath(graph, edges, numNodes, src);
}