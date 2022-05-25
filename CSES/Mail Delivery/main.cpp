// https://cses.fi/problemset/task/1691/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> visited_edge(m, false);
    int u, v;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for(int i=1; i<=n; i++){
        if(adj[i].size() & 1){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    stack<int> s;
    vector<int> res;
    s.push(1);
    int edge;
    while(!s.empty()){
        v = s.top();
        bool found = false;
        while(!adj[v].empty()){
            u = adj[v].back().first;
            edge = adj[v].back().second;
            adj[v].pop_back();
            if(visited_edge[edge]) continue;
            s.push(u);
            visited_edge[edge] = true;
            found = true;
            break; 
        }
        if(!found){
            res.push_back(v);
            s.pop();
        }
    }
    if(res.size() != m+1) cout << "IMPOSSIBLE" << endl;
    else {for(int v : res) cout << v << ' ';}
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // for(ll t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
        solve();
    // }
    
    return 0;
}