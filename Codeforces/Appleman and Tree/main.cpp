// https://codeforces.com/contest/461/problem/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

void dfs(vector<vector<int>>& adj, vector<int>& colors, vector<vector<ll>>& dp, int node, int par){
    
    //code calculates the DP table while regarding that the node is white
    dp[node][0] = 1; //if leaf node and it is white, number of ways of having all-white component is 1
    dp[node][1] = 0; //if leaf node and it is white, number of ways of having 1-black component is 0

    for(auto child : adj[node]){
        if(child != par){
            dfs(adj, colors, dp, child, node);

            dp[node][1] *= dp[child][0]; // 1-black node can be connected with any child component which is all-white
            dp[node][1] %= mod;

            dp[node][1] += dp[node][0]*dp[child][1]; // all-white node can be connected with any child component which is 1-black,
                                                     // and then that entire component is added to dp[node][1] because now it has 1 black node
            dp[node][1] %= mod;

            dp[node][0] *= dp[child][0]; // white node can be connected to any child component which is all-white
            dp[node][0] %= mod;
        }
    }

    if(colors[node]==1){
        dp[node][1] = dp[node][0]; // if node itself is black, 1-black components can't be added to it, so it becomes equal to all-white components
        dp[node][1] %= mod;
    }
    else{
        dp[node][0] += dp[node][1]; // if node itself is white, it can be part of all 1-black components
        dp[node][0] %= mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;

    // adjacency list for the tree
    vector<vector<int>> adj(n);
    for(int i=1; i<=n-1; i++){
        int p; cin>>p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    vector<int> colors(n);
    for(int i=0; i<n; i++) cin>>colors[i];

    // DP[v][0] = the number of ways that the subtree rooted at vertex v has no black vertex.
    // DP[v][1] = the number of ways that the subtree rooted at vertex v has one black vertex.
    vector<vector<ll>> dp(n, vector<ll>(2));
    dfs(adj, colors, dp, 0, -1);

    cout << dp[0][1] << endl;

    return 0;
}