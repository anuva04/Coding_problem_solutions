// https://www.spoj.com/problems/GOODA/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<ll>> g, gt, condensed_scc;
vector<bool> used;
vector<ll> order, component, roots, root_nodes, cost;
map<ll, ll> weight;

void dfs1(ll v){
    used[v] = true;
    for(auto u : g[v]){
        if(!used[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(ll v){
    used[v] = true;
    component.push_back(v);
    for(auto u : gt[v]){
        if(!used[u]) dfs2(u);
    }
}

void solve(){
    ll n, m, s, e;
    cin>>n>>m>>s>>e;
    cost.resize(n+1);
    g.resize(n+1);
    gt.resize(n+1);
    for(ll i=1; i<=n; i++) cin>>cost[i];
    ll u, v;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }
    used.assign(n+1, false);
    for(ll i=1; i<=n; i++) {
        if(!used[i]) dfs1(i);
    }
    used.assign(n+1, false);
    reverse(order.begin(), order.end());
    roots.assign(n+1, 0);
    condensed_scc.resize(n+1);
    ll source, dest;
    for(auto v : order){
        if(!used[v]){ 
            dfs2(v);
            ll root = component.front();
            for(auto u : component){
                roots[u] = root;
                weight[root] += cost[u];
            }
            root_nodes.push_back(root);
            component.clear();
        }
    }
    for(ll v=1; v<=n; v++){
        for(auto u : g[v]){
            ll root_v = roots[v];
            ll root_u = roots[u];
            if(root_v != root_u) condensed_scc[root_v].push_back(root_u);
        }
    }

    source = roots[s], dest = roots[e];
    vector<ll> dist(n+1, -INF);
    dist[source] = weight[source];
    vector<ll> indegree(n+1, 0);
    for(auto v : condensed_scc){
        if((int)v.size() == 0) continue;
        for(auto u : v) indegree[u]++;
    }
    queue<ll> q;
    for(ll i=1; i<=n; i++){
        if(indegree[i] == 0 && (int)condensed_scc[i].size() != 0) q.push(i);
    }
    while(!q.empty()){
        ll node = q.front();
        q.pop();
        for(auto nei : condensed_scc[node]) {
            indegree[nei]--;
            if(indegree[nei] == 0) q.push(nei);
        }
        if(dist[node] != -INF){
            for(auto nei : condensed_scc[node]){
                if(dist[nei] < weight[nei] + dist[node]){
                    dist[nei] = dist[node] + weight[nei];
                }
            }
        }
    }
    cout << dist[dest] << endl;
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