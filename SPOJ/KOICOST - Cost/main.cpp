// https://www.spoj.com/problems/KOICOST/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000000
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<pair<int, pii>> edges;
vector<int> parent;
vector<ll> sz, sum;

int findParent(int v){
    if(parent[v] != v) parent[v] = findParent(parent[v]);
    return parent[v];
}

void solve(){
    int n, m; cin>>n>>m;
    if(m == 0) {
        cout << 0 << endl;
        return;
    }
    int u, v, w;
    for(int i=0; i<m; i++) {
        cin>>u>>v>>w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    sz.assign(n+1, 1);
    parent.resize(n+1);
    iota(parent.begin(), parent.end(), 0);
    sum.assign(m, 0);
    sum[0] = edges[0].first;
    for(int i=1; i<m; i++) sum[i] = edges[i].first + sum[i-1];

    ll ans = 0;
    for(int i=edges.size()-1; i>=0; i--){
        int pu = findParent(edges[i].second.first);
        int pv = findParent(edges[i].second.second);
        if(pu == pv) continue;
        ll su = sz[pu], sv = sz[pv];
        ans += (su*sv*sum[i]);
        ans %= mod;
        parent[pu] = pv;
        sz[pu] = su+sv;
        sz[pv] = su+sv;
    }
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
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}