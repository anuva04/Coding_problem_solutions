// https://www.spoj.com/problems/LOCKER/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll binpow(ll a, ll b){
    ll res = 1;
    while(b>0){
        if(b&1) res = res * a % mod;
        a = a*a%mod;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll n; cin>>n;
    ll ans;
    if(n<3){
        cout << n << endl;
        return;
    }
    if(n%3 == 1){
        ans = (4*binpow(3, (n-4)/3))%mod;
    } else if(n%3 == 2){
        ans = binpow(3, n/3);
        ans = ans * 2 % mod;
    } else {
        ans = binpow(3, n/3);
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