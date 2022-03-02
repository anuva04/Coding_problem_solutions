// https://www.codechef.com/problems/REVERSE

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<pair<int,int>>> adj;

void solve(){
    int n, m; cin>>n>>m;
    adj.resize(n+1);
    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back({y, 0});
        adj[y].push_back({x, 1});
    }
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    deque<int> q;
    q.push_front(1);
    while(!q.empty()){
        int v = q.front();
        q.pop_front();
        for(auto edge : adj[v]){
            int u = edge.first, cost = edge.second;
            if(dist[v] + cost < dist[u]){
                dist[u] = dist[v] + cost;
                if(cost == 1) q.push_back(u);
                else q.push_front(u);
            }
        }
    }
    cout << (dist[n]<INF ? dist[n] : -1) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

        solve();
    
    return 0;
}