// https://codeforces.com/contest/1593/problem/E

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int max_val = 2e6 + 7;

void solve(){
    int n, k; cin>>n>>k;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n-1; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        indegree[u] += 1;
        indegree[v] += 1;
    }
    vector<int> leaves;
    for(int i=1; i<=n; i++){
        if(indegree[i] <= 1) leaves.push_back(i);
    }
    vector<int> visited(n+1, false);
    while(k--){
        vector<int> new_leaves;
        for(auto leaf : leaves){
            visited[leaf] = true;
            indegree[leaf] = -1;
            for(auto nei : adj[leaf]){
                if(visited[nei]) continue;
                indegree[nei] -= 1;
                if(indegree[nei] <= 1) new_leaves.push_back(nei);
            }
        }
        if(new_leaves.size() == 0) break;
        leaves.clear();
        leaves = new_leaves;
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]) cnt += 1;
    }
    cout << cnt << endl;
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