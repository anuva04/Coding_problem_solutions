// https://www.spoj.com/problems/RPLA/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

void solve(){
    int n,r; cin>>n>>r;
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    int r1, r2;
    while(r--){
        cin>>r1>>r2;
        adj[r2].push_back(r1);
        indegree[r1]++;
    }
    vector<pair<int,int>> ans;
    int rank = 1;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int node = q.front(); q.pop();
            ans.push_back({rank, node});
            for(auto nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        rank++;
    }
    sort(ans.begin(), ans.end());
    for(auto ele : ans) cout << ele.first << ' ' << ele.second << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    // while(test--){
        // solve();
    // }

    for(ll t=1; t<=test; t++){
        cout << "Scenario #" << t << ":" << endl;
        solve();
    }
    
    return 0;
}