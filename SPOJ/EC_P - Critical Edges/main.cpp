// https://www.spoj.com/problems/EC_P/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<ll>> adj;
vector<bool> visited;
vector<ll> disc, low;
ll timer, n, m;
vector<pair<ll, ll>> bridges;

void dfs(ll v, ll p = -1){
    visited[v] = true;
    disc[v] = low[v] = timer++;
    for(ll to : adj[v]){
        if(to == p) continue;
        if(visited[to]){
            low[v] = min(low[v], disc[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > disc[v]) bridges.push_back({min(v, to), max(v, to)});
        }
    }
}

void find_bridges(){
    timer = 0;
    visited.assign(n, false);
    disc.assign(n, -1);
    low.assign(n, -1);
    for(ll i=0; i<n; i++) {
        if(!visited[i]) dfs(i);
    }
}

void solve(){
    cin>>n>>m;
    adj.clear();
    adj.resize(n);
    ll a, b;
    while(m--){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    bridges.clear();
    find_bridges();
    sort(bridges.begin(), bridges.end());
    if(bridges.size() == 0){
        cout << "Sin bloqueos" << endl;
        return;
    }
    cout << bridges.size() << endl;
    for(auto b : bridges){
        cout << b.first+1 << ' ' << b.second+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    for(ll t=1; t<=test; t++){
        cout << "Caso #" << t << endl;
        solve();
    }
    
    return 0;
}