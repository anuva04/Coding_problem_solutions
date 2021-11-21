// https://codeforces.com/contest/1602/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) cin>>a[i], mp[a[i]]++;
    vector<int> prev(n), curr(n);
    vector<vector<int>> transformations;
    transformations.push_back(a);
    for(int i=0; i<n; i++) curr[i] = mp[a[i]];
    int unique = 0;
    while(curr != prev){
        mp.clear();
        transformations.push_back(curr);
        unique++;
        prev = curr;
        for(int i=0; i<n; i++) mp[curr[i]]+=1;
        for(int i=0; i<n; i++) curr[i] = mp[prev[i]];
    }
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int x,k; cin>>x>>k;
        cout << transformations[min(k, unique)][x-1] << endl;
    }
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