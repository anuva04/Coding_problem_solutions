// https://www.spoj.com/problems/EAGLE1/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector< pair<ll,ll> >> adj;
vector<ll> dist;
vector<ll> ans;

void dfs(ll node, ll parent){
    for(auto nei : adj[node]){
        if(nei.first == parent) continue;
        dist[nei.first] = dist[node] + nei.second;
        dfs(nei.first, node);
    }
}

void solve(){
    ll n; cin>>n;

    adj = vector<vector< pair<ll,ll> >>(n+1);
    dist = vector<ll>(n+1);
    fill(dist.begin(), dist.end(), 0);
    ans = vector<ll>(n+1);
    fill(ans.begin(), ans.end(), 0);

    ll u, v, d;
    for(ll i=0; i<n-1; i++){
        cin>>u>>v>>d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    dist[1] = 0;
    dfs(1, 0);

    ll diameter_node = 0;
    for(ll i=1; i<=n; i++){
        if(dist[i] > dist[diameter_node]) diameter_node = i;
    }

    dist[diameter_node] = 0;
    dfs(diameter_node, 0);

    ll other_diameter_node = 0;

    for(ll i=1; i<=n; i++){
        if(dist[i] > dist[other_diameter_node]) other_diameter_node = i;
        ans[i] = max(ans[i], dist[i]);
    }

    dist[other_diameter_node] = 0;
    dfs(other_diameter_node, 0);

    for(ll i=1; i<=n; i++){
        ans[i] = max(ans[i], dist[i]);
    }

    for(ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}