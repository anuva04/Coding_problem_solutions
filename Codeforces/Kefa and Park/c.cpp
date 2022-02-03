// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int ans = 0;
vector<int> cats;
vector<vector<int>> adj;

void dfs(int node, int parent, int val, int m){
    val = (cats[node] == 1) ? val+1 : 0;
    if(val > m) return;
    bool isLeaf = true;
    for(auto nei : adj[node]){
        if(nei == parent) continue;
        dfs(nei, node, val, m);
        isLeaf = false;
    }
    if(isLeaf && val <= m) ans += 1;
    return;
}

void solve(){
    int n, m; cin>>n>>m;
    cats.resize(n+1);
    fill(cats.begin(), cats.end(), 0);
    for(int i=1; i<=n; i++){
        cin>>cats[i];
    }
    adj.resize(n+1);
    int u, v;
    for(int i=0; i<n-1; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, m);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}