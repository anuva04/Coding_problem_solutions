// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector< vector<pair<int,int>> > adj;
map<string,int> mp;

int dijkstra(int src, int dest, int n){
    vector<int> dist(n+1, INT_MAX);
    vector<bool> marked(n+1, false);
    dist[src] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, src});
    while(!q.empty()){
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if(d_v != dist[v]) continue;
        if(v == dest) return dist[v];
        for(auto edge : adj[v]){
            int to = edge.first;
            int d = edge.second;
            if(dist[v] + d < dist[to]){
                dist[to] = dist[v] + d;
                q.push({dist[to], to});
            }
        }
    }
    return dist[dest];
}

void solve(){
    int n; cin>>n;
    adj.clear();
    mp.clear();
    adj.resize(n+1);
    for(int i=1; i<=n; i++){
        string name; cin>>name;
        mp[name] = i;
        int p; cin>>p;
        while(p--){
            int v, d; cin>>v>>d;
            adj[i].push_back({v, d});
        }
    }
    int r; cin>>r;
    while(r--){
        string name1, name2; cin>>name1>>name2;
        int src = mp[name1], dest = mp[name2];
        int ans = dijkstra(src, dest, n);
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}