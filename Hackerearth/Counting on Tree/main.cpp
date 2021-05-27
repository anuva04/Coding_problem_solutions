// https://www.hackerearth.com/problem/algorithm/counting-on-tree-1/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;
vector<int> adj[1<<20]; // adjacency list for tree
int cost[1<<20]; // cost of each node
int dp[55000][101]; // main dp
int ans, k; // final ans and total sum value
long temp_dp[55000]; // temporary dp for internal computation
int subset_size[55000]; // cost of all possible connected components including node
int total_size[55000]; // total cost for the complete subtree rooted at node

void dfs(int node, int par){
    subset_size[node] = cost[node]; // when that particular node is first added to the solution
    total_size[node] = cost[node]; // when that particular node is first added to the solution

    for(auto child: adj[node]){
        if(child == par) continue;

        dfs(child, node);
        total_size[node] += total_size[child]; // total cost for entire subtree is obtained by total cost of all children plus the current node (recursively)
    }

    for(int i=0; i<=total_size[node]&&i<=k; i++) dp[node][i]=0; // clearing previous testcase values
    dp[node][cost[node]] = 1;
    for(auto child: adj[node]){
        if(child == par) continue;

        for(int i=0; i<=k&&i<=subset_size[node]+subset_size[child]; i++) temp_dp[i]=0; // clearing previous testcase values
        for(int i=0; i<=k&&i<=subset_size[node]; i++) temp_dp[i]=dp[node][i]; // temp_dp stores all possible costs from 0 to k for current node

        for(int i=0; i<=k&&i<=subset_size[node]; i++){
            for(int j=0; j<=k-i&&j<=subset_size[child]; j++){
                temp_dp[i+j] += 1ll*dp[node][i]*dp[child][j]; // number of ways a child component can be connected to a component containing the parent is equal to the multiplication of both
                if(temp_dp[i+j]>8e18) temp_dp[i+j]%=mod;
            }
        }

        for(int i=0; i<=subset_size[node]+subset_size[child]&&i<=k; i++){
            dp[node][i] = temp_dp[i]; // temp_dp values are stored back in main dp
        }
        subset_size[node] += subset_size[child];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n>>k;
        for(int i=1; i<=n; i++) cin>>cost[i];
        for(int i=1; i<=n; i++) adj[i].clear(); // clearing previous testcase values
        
        // adjacency list for tree
        for(int i=1; i<n; i++){
            int u, v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);
        ans = 0;
        for(int i=1; i<=n; i++){
            if(total_size[i]>=k){
                ans = (ans+dp[i][k])%mod;
            }
        }
        cout << ans << endl;
    }

    return 0;
}