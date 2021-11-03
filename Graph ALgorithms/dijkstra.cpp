#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int minDistance(vector<int>& dist, vector<bool>& sptSet, int numNodes)
{
    int min = INT_MAX, min_index;
 
    for (int v = 1; v <= numNodes; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void dijkstra(vector<vector<int>>& graph, int src, int V)
{
    vector<int> dist(V+1);
    vector<bool> sptSet(V+1);
 
    for (int i = 1; i <= V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
 
        sptSet[u] = true;
 
        for (int v = 1; v <= V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    for(int node = 1; node<=V; node++){
        cout << node << " : " << dist[node] << endl;
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
    dijkstra(graph, 1, numNodes);   
}