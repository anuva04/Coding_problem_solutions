#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);

void floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& minDist, vector<vector<int>>& path, int numNodes){
    for(int i=0; i<numNodes; i++){
        for(int j=0; j<numNodes; j++){
            minDist[i][j] = graph[i][j];
            if(graph[i][j]!=INF && i!=j) path[i][j] = i;
            else path[i][j] = -1;
        }
    }
    for(int k=0; k<numNodes; k++){
        for(int i=0; i<numNodes; i++){
            for(int j=0; j<numNodes; j++){
                if(minDist[i][k]==INF || minDist[k][j]==INF) continue;
                if(minDist[i][j] > minDist[i][k]+minDist[k][j]){
                    minDist[i][j] = minDist[i][k] + minDist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    for(int i=0; i<numNodes; i++){
        if(minDist[i][i] < 0){
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }
    for(int i=0; i<numNodes; i++){
        for(int j=0; j<numNodes; j++){
            cout << minDist[i][j] << " ";
        }
        cout << endl;
    }
}

void printPath(vector<vector<int>>& path, int numNodes, int src, int dest){
    if(src<0 || dest<0 || src>=numNodes || dest>=numNodes){
        cout << "Invalid Query!" << endl;
        return;
    }
    deque<int> dq;
    dq.push_back(dest);
    while(true){
        dest = path[src][dest];
        if(dest==-1) return;
        dq.push_front(dest);
        if(dest == src) break;
    }
    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
}

int main(){
    int numNodes; cin>>numNodes;
    vector<vector<int>> graph(numNodes, vector<int>(numNodes, INF));
    vector<vector<int>> minDist(numNodes, vector<int>(numNodes, INF));
    vector<vector<int>> path(numNodes, vector<int>(numNodes, 0));
    int numEdges; cin>>numEdges;
    for(int i=0; i<numEdges; i++){
        int u, v, w; cin>>u>>v>>w;
        graph[u][v] = w;
    }
    floydWarshall(graph, minDist, path, numNodes);
    int q; cin>>q;
    while(q--){
        int src, dest; cin>>src>>dest;
        printPath(path, numNodes, src, dest);
    }
}