// https://www.spoj.com/problems/GOODB/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 305
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll factorial[MAXN];

ll bin_pow(ll a, ll p){
    ll ans = 1;
    while(p){
        if(p&1) {
            ans *= a;
            ans %= mod;
        }
        a = (a*a)%mod;
        p >>= 1;
    }
    return ans;
}

void solve(){
    ll n, w, t, r;
    cin>>n>>w>>t>>r;
    factorial[0] = 1;
    for(ll i=1; i<=n; i++) factorial[i] = factorial[i-1]*i%mod;
    
    ll inv_w = bin_pow(factorial[w], mod-2)%mod;
    ll inv_t = bin_pow(factorial[t], mod-2)%mod;
    ll inv_r = bin_pow(factorial[r], mod-2)%mod;

    ll ans = factorial[n];
    ans = ans*inv_w%mod;
    ans = ans*inv_r%mod;
    ans = ans*inv_t%mod;

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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}