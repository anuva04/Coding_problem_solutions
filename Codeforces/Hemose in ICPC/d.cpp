// https://codeforces.com/problemset/problem/1592/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int N = 1005;
vector<int> adj[N];
int traversal[N], parent[N];
int cnt, n;

int query(int x){
    cout << "? " << x << " ";
    for(int i=1; i<=x; i++) cout << traversal[i] << " ";
    cout << endl;
    int val; cin>>val;
    return val;
}

void dfs(int node){
    traversal[++cnt] = node;
    for(auto nei : adj[node]){
        if(nei != parent[node])parent[nei] = node, dfs(nei);
    }
}

int main(){

    cin>>n;
    for(int i=1; i<n; i++){
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);

    int max_val = query(n);
    int left = 2, right = n, step;
    while(left <= right){
        int mid = (left+right)/2;
        if(query(mid) == max_val) right = mid-1, step = mid;
        else left = mid+1;
    }
    cout << "! " << traversal[step] << " " << parent[traversal[step]] << endl;
    
    return 0;
}