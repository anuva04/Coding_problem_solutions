// https://www.codechef.com/MAY21B/problems/VPATH

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

// for finding vertical simple paths (similar to finding combinations)
void dfs1(ll node, ll parent, vector<vector<ll>>& adj, vector<ll>& vertical){
    vertical[node] = 1;
    for(ll child : adj[node]){
        if(child != parent){
            dfs1(child, node, adj, vertical);
            vertical[node] += ((vertical[child]*2)%mod);
            vertical[node] = vertical[node]%mod;
        }
    }
}

// for joining 2 vertical simple paths
void dfs2(ll node, ll parent, vector<vector<ll>>& adj, vector<ll>& vertical, vector<ll>& total){
    total[node] = 1;
    ll total_vertical_child = 0;
    for(ll child : adj[node]){
        if(child != parent){
            dfs2(child, node, adj, vertical, total);
            //cout << node << " " << child << " " << vertical[child] << " " << total[child] << endl;
            //total[node] += ((total[child] + vertical[child])%mod);
            // add total of children
            total[node] += total[child];
            total[node] = total[node]%mod;
            // add current node to each child
            total[node] += vertical[child];
            total[node] = total[node]%mod;
            total_vertical_child += vertical[child];
            //total_vertical_child = total_vertical_child%mod;
        }
    }
    //cout << "total vertical child: " << node << " " << total_vertical_child << endl;
    // joining two vertical paths
    // once by considering the common ancestor
    // once without considering common ancestor
    for(ll child : adj[node]){
        if(child != parent){
            ll total_joined = ((vertical[child]*(total_vertical_child-vertical[child])%mod)%mod);
            total[node] += total_joined;
            total[node] = total[node]%mod;
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<vector<ll>> adj(n+1);
        for(ll i=0; i<n-1; i++){
            ll u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<ll> vertical(n+1);
        dfs1(1, 0, adj, vertical);
        // for(int i=0; i<=n; i++){
        //     cout << vertical[i] << " ";
        // }
        // cout << endl;
        vector<ll> total(n+1);
        dfs2(1, 0, adj, vertical, total);
        // for(int i=0; i<=n; i++){
        //     cout << total[i] << " ";
        // }
        // cout << endl;
        cout << total[1] << endl;
    }
}