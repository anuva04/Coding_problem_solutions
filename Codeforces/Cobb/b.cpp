// https://codeforces.com/contest/1554/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) cin>>a[i];
    int limit = max(1, n-2*k);
    ll ans = -1e12;
    for(int i=limit; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans = max(ans, 1LL*i*j - 1LL*k*(a[i]|a[j]));
        }
    }
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}