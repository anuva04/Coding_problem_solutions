#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int tspUtil(vector<vector<int>>& graph, int n, int pos, vector<vector<int>>& dp, int mask, int VISITED_ALL){
    if(mask == VISITED_ALL) return graph[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int city = 0; city<n; city++){
        if((mask & (1<<city)) == 0){
            int newAns = graph[pos][city] + tspUtil(graph, n, city, dp, mask | (1<<city), VISITED_ALL);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int tsp(vector<vector<int>>& graph, int pos){
    int n = graph.size();
    vector<vector<int>> dp((1<<n), vector<int>(n,-1));
    int VISITED_ALL = (1<<n) - 1;
    return tspUtil(graph, n, 0, dp, 0, VISITED_ALL);
}

int main(){
    int n; cin>>n;
    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) cin>>graph[i][j];
    }
    cout << tsp(graph, 0) << endl;
    return 0;
}