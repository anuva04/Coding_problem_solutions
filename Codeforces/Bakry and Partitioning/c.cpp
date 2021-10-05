// https://codeforces.com/problemset/problem/1592/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int n = 1e5 + 5,k;
vector<vector<int>> adj(n);
vector<int> a(n);
vector<int> subtree_xor(n);
int xor_val;
bool possible_disjoint_subtree;

void dfs1(int node, int parent){
    subtree_xor[node] = a[node];
    for(int nei : adj[node]){
        if(nei != parent){
            dfs1(nei, node);
            subtree_xor[node] ^= subtree_xor[nei];
        }
    }
}

bool dfs2(int node, int parent, bool possible_ancestor_subtree){
    if(possible_ancestor_subtree && subtree_xor[node]==xor_val) return true;
    if(subtree_xor[node]==xor_val && possible_disjoint_subtree) return true;

    if(subtree_xor[node]==0) possible_ancestor_subtree = true;
    for(int nei : adj[node]){
        if(nei != parent){
            if(dfs2(nei, node, possible_ancestor_subtree)) return true;
        }
    }
    if(subtree_xor[node] == xor_val) possible_disjoint_subtree = true;
    return false;
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
        possible_disjoint_subtree = false;
        xor_val = 0;
        int x = 0;
        cin>>n>>k;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            a[i] = 0;
            subtree_xor[i] = 0;
        }
        
        for(int i=1; i<=n; i++){
            cin>>a[i];
            x ^= a[i];
        }
        xor_val = x;
        
        for(int i=1; i<=n-1; i++){
            int u,v; cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(xor_val==0) cout << "YES" << endl;
        else if(k==2) cout << "NO" << endl;
        else{
            
            dfs1(1, 1);
            if(dfs2(1, 1,false)) cout << "YES" << endl;
            else cout << "NO" << endl;
        } 
    }
    
    return 0;
}