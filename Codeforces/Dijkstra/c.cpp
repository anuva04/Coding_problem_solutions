// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll INF = 1000000000000;

vector<vector<pair<ll, ll>>> adj;

void dijkstra(ll s, vector<ll> & d, vector<ll> & p, ll n) {
    d.assign(n+1, INF);
    p.assign(n+1, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}

void solve(){
    ll n, m; cin>>n>>m;
    adj.resize(n+1);
    ll u, v, len;
    while(m--){
        cin>>u>>v>>len;
        adj[u].push_back({v, len});
        adj[v].push_back({u, len});
    }
    vector<ll> d, p;
    dijkstra(1, d, p, n);
    if(d[n] == INF) {
        cout << -1 << endl;
        return;
    }
    vector<ll> path;
    for(ll v = n; v!=1; v = p[v]) path.push_back(v);
    path.push_back(1);
    for(ll i=path.size()-1; i>=0; i--) cout << path[i] << ' '; cout << endl;
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