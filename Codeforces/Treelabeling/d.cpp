// https://codeforces.com/contest/1605/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector<ll>> adj;
vector<vector<ll>> mp(2);

void dfs(ll node, ll parent, ll level){
    mp[level].push_back(node);
    for(auto nei : adj[node]){
        if(nei == parent) continue;
        dfs(nei, node, !level);
    }
}

void solve(){
    ll n; cin>>n;
    adj.assign(n+1, {});
    for(int i=1; i<=n-1; i++){
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mp[0].clear();
    mp[1].clear();
    dfs(1, -1, 1);
    if(mp[0].size() > mp[1].size()) swap(mp[0], mp[1]);
    ll min_size = mp[0].size();
    vector<ll> ans(n+1, 0);
    for(int i=1; i<=n; i++){
        ll msb = 31 - __builtin_clz(i);
        if(min_size & (1<<msb)){
            ans[mp[0].back()] = i;
            mp[0].pop_back();
        } else {
            ans[mp[1].back()] = i;
            mp[1].pop_back();
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}