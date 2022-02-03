// https://www.spoj.com/problems/MICEMAZE/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<pair<int,int>>> adj;
vector<int> dist;

void dijkstra(int e, int n){
    dist.resize(n+1);
    fill(dist.begin(), dist.end(), INF);

    dist[e] = 0;
    priority_queue< pii, vector<pii>, greater<pii> > q;
    q.push({0, e});

    while(!q.empty()){
        int d = q.top().first;
        int node = q.top().second;
        q.pop();

        if(d != dist[node]) continue;

        for(auto edge : adj[node]){
            int nei = edge.first;
            int len = edge.second;
            if(dist[node] + len < dist[nei]){
                dist[nei] = dist[node] + len;
                q.push({dist[nei], nei});
            }
        }
    }
}

void solve(){
    int n, e, t; cin>>n>>e>>t;
    adj.resize(n+1);
    int m; cin>>m;
    int u, v, d;
    while(m--){
        cin>>u>>v>>d;
        adj[v].push_back({u, d});
    }
    dijkstra(e, n);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(dist[i] <= t) cnt++;
    }
    cout << cnt << endl;
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