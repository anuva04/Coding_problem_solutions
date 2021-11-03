#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int minKey(vector<int>& key, vector<bool>& mstSet, int numNodes){
    int min=INT_MAX, min_index;
    for(int v=1; v<=numNodes; v++){
        if(!mstSet[v] && key[v]<min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void primMst(vector<vector<int>>& graph, int numNodes){
    vector<int> parent(numNodes+1);
    vector<int> key(numNodes+1, INT_MAX);
    vector<bool> mstSet(numNodes+1, false);
    key[1] = 0;
    parent[1] = -1;
    for(int cnt=0; cnt<numNodes-1; cnt++){
        int u = minKey(key, mstSet, numNodes);
        mstSet[u] = true;
        for(int v=1; v<=numNodes; v++){
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    for(int i=2; i<=numNodes; i++){
        cout << parent[i] << " - " << i << " " << graph[i][parent[i]]<<" \n";
    }
}

int main(){
    int numNodes; cin>>numNodes;
    vector<vector<int>> graph(numNodes+1, vector<int>(numNodes+1));
    for(int i=1; i<=numNodes; i++){
        for(int j=1; j<=numNodes; j++){
            cin>>graph[i][j];
        }
    }
    primMst(graph, numNodes);
}