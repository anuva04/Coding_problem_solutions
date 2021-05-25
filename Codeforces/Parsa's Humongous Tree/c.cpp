// https://codeforces.com/contest/1529/problem/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<vector<ll>>& adj, vector<pair<ll,ll>>& lr, vector<vector<ll>>& dp, ll node, ll parent){
    for(auto nei : adj[node]){
        if(nei != parent){
            dfs(adj, lr, dp, nei, node);
            dp[node][0] += max(abs(lr[node].first - lr[nei].first)+dp[nei][0], abs(lr[node].first - lr[nei].second)+dp[nei][1]);
            dp[node][1] += max(abs(lr[node].second - lr[nei].first)+dp[nei][0], abs(lr[node].second - lr[nei].second)+dp[nei][1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<pair<ll,ll>> lr(n+1);
        for(ll i=1; i<=n; i++){
            ll l,r; cin>>l>>r;
            lr[i] = {l,r};
        }
        vector<vector<ll>> adj(n+1);
        for(ll i=1; i<n; i++){
            ll u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<ll>> dp(n+1, vector<ll>(2));
        dfs(adj, lr, dp, 1,-1);
        cout << max(dp[1][0], dp[1][1]) << endl;
    }
    return 0;
}