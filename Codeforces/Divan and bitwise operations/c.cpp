// https://codeforces.com/contest/1614/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll p = power(x, y / 2) % mod;
    p = (p * p) % mod;
 
    return (y % 2 == 0) ? p : (x * p) % mod;
}

void solve(){
    ll n, m;
    cin>>n>>m;
    ll bitwise_or = 0;
    for(int i=0; i<m; i++){
        ll l, r, x;
        cin>>l>>r>>x;
        bitwise_or |= x;
    }
    bitwise_or %= mod;
    ll ans = 0;
    ans = power(2, n-1);
    ans %= mod;
    ans *= bitwise_or;
    ans %= mod;
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