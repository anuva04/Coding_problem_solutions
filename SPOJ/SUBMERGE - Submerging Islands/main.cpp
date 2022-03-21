// https://www.spoj.com/problems/SUBMERGE/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> disc, low;
int timer;
unordered_set<int> articulation_points;

void dfs(int v, int p = -1){
    visited[v] = true;
    disc[v] = low[v] = timer++;
    int children = 0;
    for(int to : adj[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], disc[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= disc[v] && p != -1) articulation_points.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1) articulation_points.insert(v);
}

void find_articulation_points(int n){
    timer = 0;
    articulation_points.clear();
    visited.assign(n+1, false);
    disc.assign(n+1, -1);
    low.assign(n+1, -1);
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }

}

void solve(int n){
    int m; cin>>m;
    int u, v;
    adj.clear();
    adj.resize(n+1);
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_articulation_points(n);
    cout << (int)articulation_points.size() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while(cin>>n && n){
        solve(n);
    }

    // ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}