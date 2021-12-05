#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int tsp(vector<vector<int>>& graph, int n, int s) {
    vector<int> vertex;
    for (int i = 0; i < n; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int curr_weight = 0;
        int curr_vertex = s;
        
        for (int i = 0; i < vertex.size(); i++) {
            curr_weight += graph[curr_vertex][vertex[i]];
            curr_vertex = vertex[i];
        }
        curr_weight += graph[curr_vertex][s];
 
        min_path = min(min_path, curr_weight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>graph[i][j];
    }
    int src; cin>>src;
    cout << tsp(graph, n, src) << endl;
    return 0;
}