// https://cses.fi/problemset/task/1669/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parent;
int cycle_start, cycle_end, n, m;

bool dfs(int v, int par){
    visited[v] = true;
    for(int u : adj[v]){
        if(u == par) continue;
        if(visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if(dfs(u, v)) return true;
    }
    return false;
}

void find_cycle(){
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    cycle_start = -1;
    for(int v=1; v<=n; v++){
        if(!visited[v] && dfs(v, parent[v])) break;
    }
    if(cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for(int v=cycle_end; v!=cycle_start; v=parent[v]) cycle.push_back(v);
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << (int)cycle.size() << endl;
    for(auto ele : cycle) cout << ele << ' '; cout << endl;
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    int a, b;
    while(m--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    find_cycle();
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