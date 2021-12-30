// https://codeforces.com/contest/1591/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

struct DSU {
    vector<int> parent, sz;
    int num_connected;
    void build(int n){
        parent.resize(n+1);
        sz.resize(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
        num_connected = n;
    }
    int getParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }
    int getComponentSize(int x){
        return sz[getParent(x)];
    }
    void unionComponents(int x, int y){
        x = getParent(x);
        y = getParent(y);
        if(x == y) return;
        sz[x] += sz[y];
        sz[y] = 0;
        parent[y] = x;
        num_connected--;
    }
};

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto ele : mp){
        if(ele.second > 1){
            cout << "YES" << endl;
            return;
        }
    }
    DSU dsu;
    dsu.build(n+1);
    for(int i=0; i<n; i++) dsu.unionComponents(a[i], i+1);
    int num_even_comps = 0;
    for(int i=0; i<n; i++){
        if(dsu.sz[i+1]>0 && dsu.sz[i+1]%2==0) num_even_comps++;
    }
    cout << ((num_even_comps&1) ? "NO" : "YES") << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}