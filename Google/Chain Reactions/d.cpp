// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a45ef7

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 1e18;

ll ans = 0;

void dfs(vector<vector<ll>>& adj, vector<ll>& mx, vector<ll>& f, ll node){
    if(adj[node].size() == 0) {
        mx[node] = f[node];
        return;
    }
    for(auto nei : adj[node]) dfs(adj, mx, f, nei);
    if(adj[node].size() == 1){
        mx[node] = max(mx[adj[node][0]], f[node]);
    } else {
        ll mn = INF, mn_idx = -1;
        for(ll i=0; i<adj[node].size(); i++){
            if(mx[adj[node][i]] < mn){
                mn = mx[adj[node][i]];
                mn_idx = i;
            }
        }
        for(ll i=0; i<adj[node].size(); i++){
            if(i != mn_idx) ans += mx[adj[node][i]];
            else mx[node] = max(f[node], mx[adj[node][i]]);
        }
    }
}

void solve(){
    ll n; cin>>n;
    vector<ll> f(n+1), p(n+1), indegree(n+1, 0);
    for(ll i=1; i<=n; i++) cin>>f[i];
    for(ll i=1; i<=n; i++) {cin>>p[i]; indegree[p[i]]++;}
    vector<vector<ll>> adj(n+1);
    vector<ll> mx(n+1, -INF);
    for(ll i=1; i<=n; i++) adj[p[i]].push_back(i);
    ans = 0;
    dfs(adj, mx, f, 0);
    ans += mx[0];
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test; cin>>test;

    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}