// https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a33bc7

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 1e18;

vector<vector<pii>> adj(1001);

pair<ll, int> dfs(int node, int parent){
    pair<ll, int> ans = {0, node};
    for(auto nei : adj[node]){
        if(nei.first == parent) continue;
        pair<ll, int> new_ans = dfs(nei.first, node);
        new_ans.first += nei.second;
        ans = max(ans, new_ans);
    }
    return ans;
}

void solve(){
    int n; cin>>n;
    for(int i=0; i<=n; i++) adj[i].clear();
    int a, b, c; 
    ll total = 0;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c; 
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        total += c;
    }
    auto ans = dfs(1, -1);
    ans = dfs(ans.second, -1);
    ll res = 2*total - ans.first;
    cout << res << endl;
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