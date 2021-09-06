// https://codeforces.com/problemset/problem/1534/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);
const int MN=4e5+1;

vector<vector<int>> adj(MN, vector<int>());
bool visited[MN+1];
void dfs(int node){
    visited[node] = true;
    for(auto nei : adj[node]){
        if(!visited[nei]) dfs(nei);
    }
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
        int n; cin>>n;
        int a[n], b[n];
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++) cin>>b[i];
        for(int i=0; i<=n; i++){
            visited[i] = false;
            adj[i].clear();
        }

        for(int i=0; i<n; i++){
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        ll ans = 1;
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                ans = ans*ll(2) % mod;
                dfs(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}