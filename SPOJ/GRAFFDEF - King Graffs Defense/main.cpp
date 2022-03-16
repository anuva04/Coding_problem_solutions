// https://www.spoj.com/problems/GRAFFDEF/

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
vector<ll> disc, low, component_sizes;
ll timer, n, m, cnt;
set<pair<ll, ll>> bridges;

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
            if(low[to] > disc[v]) bridges.insert({v, to});
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

void dfs1(ll v){
    visited[v] = true;
    cnt++;
    for(auto to : adj[v]){
        if(!visited[to]) dfs1(to);
    }
}

void find_connected_components(){
    visited.assign(n, false);
    for(ll i=0; i<n; i++){
        if(!visited[i]){
            cnt = 0;
            dfs1(i);
            component_sizes.push_back(cnt);
        }
    }
}

void solve(){
    cin>>n>>m;
    adj.resize(n);
    vector<pair<ll,ll>> edges;
    ll a, b;
    while(m--){
        cin>>a>>b;
        edges.push_back({a-1,b-1});
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    find_bridges();
    // cout << bridges.size() << endl;
    adj.clear(); adj.resize(n);
    for(auto edge : edges){
        if(bridges.count({edge.first, edge.second}) || bridges.count({edge.second, edge.first})) continue;
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }
    find_connected_components();
    ll total_ways = 1LL*n*(n-1)/2;
    ll ways_in_different_components = 0LL;
    for(ll i=0; i<component_sizes.size(); i++){
        for(ll j=i+1; j<component_sizes.size(); j++){
            ways_in_different_components += (component_sizes[i]*component_sizes[j]);
        }
    }
    ld ans = (ld)((ld)ways_in_different_components/total_ways);
    cout << fixed << setprecision(5) << ans << endl;
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