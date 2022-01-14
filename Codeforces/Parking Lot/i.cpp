// http://codeforces.com/problemset/problem/630/I

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll binpow(ll x, ll y){
    ll ans = 1;
    while(y>0){
        if(y&1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

void solve(){
    ll n; cin>>n;
    ll ans = binpow(4, n-3) * 4 * 3 * 2;
    if(n>3) ans += (n-3)*4*9*binpow(4, n-4);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}