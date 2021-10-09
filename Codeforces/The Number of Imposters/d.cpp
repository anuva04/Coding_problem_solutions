// https://codeforces.com/contest/1594/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj_color(n+1);
    // edge = 0 implies imposter
    // edge = 1 implies crewmate
    for(int i=0; i<m; i++){
        int u,v; string c; cin>>u>>v>>c;
        if(c == "crewmate"){
            adj_color[u].push_back({v, 1});
            adj_color[v].push_back({u, 1});
        } else{
            adj_color[u].push_back({v, 0});
            adj_color[v].push_back({u, 0});
        }
    }

    vector<int> color(n+1, -1);
    queue<int> bfs;
    bool contradiction = false;
    int ans = 0;
    for(int i=1; i<=n; i++){
        int color1 = 0, color2 = 0;
        if(color[i] == -1){
            bfs.push(i);
            color[i] = 1;
            while(!bfs.empty()){
                int node = bfs.front();
                bfs.pop();
                if(color[node] == 1) color1++;
                else color2++;
                for(auto nei : adj_color[node]){
                    int v = nei.first;
                    int edge_type = nei.second;
                    if(color[v] != -1){
                        if(edge_type == 0 && color[node]==color[v]) contradiction = true;
                        if(edge_type == 1 && color[node] != color[v]) contradiction = true;
                        continue;
                    }

                    if(edge_type == 0) color[v] = color[node]^1;
                    else color[v] = color[node];
                    bfs.push(v);
                }
            }
        }
        ans += max(color1, color2);
    }

    if(contradiction) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}