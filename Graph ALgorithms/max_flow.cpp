#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& residualCapacity, map<int, int>& parent, int source, int sink){
    set<int> visited;
    queue<int> q;
    q.push(source);
    visited.insert(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<residualCapacity.size(); v++){
            if(visited.find(v)==visited.end() && residualCapacity[u][v]>0){
                parent[v] = u;
                visited.insert(v);
                q.push(v);
                if(v == sink) return true;
            }
        }
    }
    return false;
}

void printAugmentedPath(vector<vector<int>>& augmentedPaths){
    for(auto path : augmentedPaths){
        for(auto ele : path) cout << ele << " -> ";
        cout << endl;
    }
}

int maxFlow(vector<vector<int>>& capacity, int source, int sink){
    int numNodes = capacity.size();
    vector<vector<int>> residualCapacity(capacity);
    map<int, int> parent;
    vector<vector<int>> augmentedPaths;
    int maxF = 0;
    while(bfs(residualCapacity, parent, source, sink)){
        vector<int> augmentedPath;
        int flow = INT_MAX;
        int v = sink;
        while(v != source){
            augmentedPath.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v]) flow = residualCapacity[u][v];
            v = u;
        }
        augmentedPath.push_back(source);
        reverse(augmentedPath.begin(), augmentedPath.end());
        augmentedPaths.push_back(augmentedPath);
        maxF += flow;
        v = sink;
        while(v != source){
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v = u;
        }
    }
    printAugmentedPath(augmentedPaths);
    return maxF;
}

int main(){
    int numNodes; cin>>numNodes;
    vector<vector<int>> capacity(numNodes, vector<int>(numNodes));
    for(int i=0; i<numNodes; i++){
        for(int j=0; j<numNodes; j++) cin>>capacity[i][j];
    }
    int source, sink; cin>>source>>sink;
    cout << maxFlow(capacity, source, sink) << endl;
}