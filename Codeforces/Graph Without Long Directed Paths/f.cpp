// https://codeforces.com/contest/1144/problem/F

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
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;
    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        edges.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> side(n+1, -1);
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(side[i] != -1) continue;
        q.push(i);
        side[i] = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            for(int nei : adj[node]){
                if(side[nei] == -1){
                    side[nei] = side[node]^1;
                    q.push(nei);
                } else if(side[node] == side[nei]){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    string ans = "";
    for(int i=0; i<m; i++){
        if(side[edges[i].first] == 0) ans.push_back('0');
        else ans.push_back('1');
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // for(ll t=1; t<=test; t++){
    //     cout << "Scenario #" << t << ":" << endl;
        solve();
    // }
    
    return 0;
}