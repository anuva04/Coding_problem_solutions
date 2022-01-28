// https://codeforces.com/contest/1631/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];
    int mx1 = *max_element(a.begin(), a.end());
    int mx2 = *max_element(b.begin(), b.end());
    if(mx1 < mx2) swap(a,b);
    mx1 = *max_element(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(a[i] == mx1) continue;
        if(a[i] < b[i]) swap(a[i], b[i]);
    }
    mx2 = *max_element(b.begin(), b.end());
    int ans = mx1 * mx2;
    cout << ans << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}