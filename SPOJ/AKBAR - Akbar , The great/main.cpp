// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, r, m; cin>>n>>r>>m;
    vector<vector<int>> adj(n+1);
    queue<pair<int, int>> bfs;
    vector<int> visited(n+1, 0);

    int a, b;
    for(int i=0; i<r; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        bfs.push({a, b});
        visited[a] = a;
    }
    while(!bfs.empty()){
        auto ele = bfs.front();
        bfs.pop();
        int node = ele.first;
        int strength = ele.second;
        if(strength <= 0) continue;
        for(auto nei : adj[node]){
            if(visited[nei] == 0){
                visited[nei] = visited[node];
                bfs.push({nei, strength-1});
            } else {
                if(visited[nei] == visited[node]) continue;
                cout << "No" << endl;
                return; 
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(visited[i] == 0){
            cout << "No" << endl;
            return; 
        }
    }
    cout << "Yes" << endl;
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}