// program to find articulation points in a graph

#include <bits/stdc++.h>
using namespace std;

int curr_time;

void dfs(map<int, vector<int>>& graph, set<int>& visited, vector<int>& articulationPoints, int vertex, map<int, int>& visitedTime, map<int, int>& lowTime, map<int, int>& parent){
    visited.insert(vertex);
    visitedTime[vertex] = curr_time;
    lowTime[vertex] = curr_time;
    curr_time++;
    int childCount = 0;
    bool isArticulationPoint = false;
    for(auto nei : graph[vertex]){
        if(nei == parent[vertex]) continue;
        if(visited.find(nei) == visited.end()){
            parent[nei] = vertex;
            childCount++;
            dfs(graph, visited, articulationPoints, nei, visitedTime, lowTime, parent);
            if(visitedTime[vertex] <= lowTime[nei]) isArticulationPoint = true;
            else lowTime[vertex] = min(lowTime[vertex], lowTime[nei]);
        } else lowTime[vertex] = min(lowTime[vertex], visitedTime[nei]);
    }
    if((parent[vertex]==-1 && childCount>=2) || (parent[vertex]!=-1 && isArticulationPoint)) articulationPoints.push_back(vertex);
}

void findArticulationPoints(map<int, vector<int>>& graph){
    curr_time = 0;
    set<int> visited;
    vector<int> articulationPoints;
    int startVertex = graph.begin()->first;
    map<int, int> visitedTime;
    map<int, int> lowTime;
    map<int, int> parent;
    parent[startVertex] = -1;
    dfs(graph, visited, articulationPoints, startVertex, visitedTime, lowTime, parent);
    for(auto ele : articulationPoints) cout << ele << " "; cout << endl;
}

int main(){
    map<int, vector<int>> graph;
    int numEdges; cin>>numEdges;
    while(numEdges--){
        int u, v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    findArticulationPoints(graph);
}