// https://www.spoj.com/problems/MARYBMW/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 1e18;

struct Edge {
    ll u, v, weight;
    Edge(ll a, ll b, ll w){
        u = a;
        v = b;
        weight = w;
    }
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

ll n, m;
vector<Edge> edges, result;
vector<ll> parent, ranks;

void make_set(ll v){
    parent[v] = v;
    ranks[v] = 0;
}

ll find_set(ll v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(ranks[a] < ranks[b]) swap(a, b);
        parent[b] = a;
        if(ranks[a] == ranks[b]) ranks[a]++;
    }
}

void solve(){
    cin>>n>>m;
    edges.clear();
    result.clear();
    ll u, v, w;
    for(ll i=0; i<m; i++){
        cin>>u>>v>>w;
        edges.push_back(Edge(u,v,w));
    }
    parent.clear(); parent.resize(n+1);
    ranks.clear(); ranks.resize(n+1);
    for(ll i=1; i<=n; i++) make_set(i);
    sort(edges.begin(), edges.end());
    for(Edge e : edges){
        if(find_set(e.u) != find_set(e.v)){
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    vector<vector<pair<ll,ll>>> adj(n+1);
    for(Edge e : result){
        adj[e.u].push_back({e.v, e.weight});
        adj[e.v].push_back({e.u, e.weight});
    }

    queue<pair<ll, ll>> q;
    q.push({1, INF});
    vector<bool> visited(n+1, false);
    visited[1] = true;

    while(!q.empty()){
        auto node = q.front();
        q.pop();
        if(node.first == n){
            cout << node.second << endl;
            return;
        }
        for(auto nei : adj[node.first]){
            if(visited[nei.first]) continue;
            visited[nei.first] = true;
            ll w = min(node.second, nei.second);
            q.push({nei.first, w});
        }
    }
    cout << -1 << endl;
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
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}