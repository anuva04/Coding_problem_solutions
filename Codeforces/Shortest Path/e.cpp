// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;

const int maxn = 3001;

vector<vector<int>> adj;
set<pair<int, pair<int,int>>> forbidden;
vector<vector<int>> dist;
vector<vector<int>> grand_parent;

void dijkstra() {
    
    dist[1][1] = 0;
    queue<pair<int, pair<int,int>>> q;
    q.push({0, {1, 1}});
    while(!q.empty()){
        auto top = q.front();
        q.pop();
        int d = top.first;
        int par = top.second.first;
        int node = top.second.second;

        for(auto nei : adj[node]){
            if(forbidden.find({par, {node, nei}}) != forbidden.end()) continue;
            if(dist[par][node] + 1 < dist[node][nei]){
                dist[node][nei] = 1 + dist[par][node];
                grand_parent[node][nei] = par;
                q.push({dist[node][nei], {node, nei}});
            }
        }
    }
}

void solve(){
    
    int n, m,k; cin>>n>>m>>k;
    adj.resize(n+1);
    int u, v;
    while(m--){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a, b, c;
    while(k--){
        cin>>a>>b>>c;
        forbidden.insert({a,{b,c}});
    }

    dist = vector<vector<int>>(n+1, vector<int>(n+1, INF));
    grand_parent = vector<vector<int>>(n+1, vector<int>(n+1, 0));

    dijkstra();

    int shortest = INF;
    int parent;
    for(int i=1; i<=n; i++){
        if(dist[i][n] < shortest){
            shortest = dist[i][n];
            parent = i;
        }
    }
    if(shortest == INF){
        cout << -1 << endl;
        return;
    }
    cout << shortest << endl;
    vector<int> path;
    int node = n;
    while(parent != 0){
        int grand = grand_parent[parent][node];
        path.push_back(node);
        node = parent;
        parent = grand;
    }
    for(int i=path.size()-1; i>=0; i--) cout << path[i] << ' '; cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}