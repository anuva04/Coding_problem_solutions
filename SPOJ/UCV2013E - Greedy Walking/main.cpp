// https://www.spoj.com/problems/UCV2013E/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 501
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

ll factorial[MAXN], inverse_factorial[MAXN], xi[MAXN], xf[MAXN], steps[MAXN], total_steps;

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
    ll n;
    while(true){
        total_steps = 0;
        cin>>n;
        if(n == 0) break;
        for(ll i=0; i<n; i++) cin>>xi[i];
        for(ll i=0; i<n; i++) {
            cin>>xf[i];
            steps[i] = xf[i] - xi[i];
            total_steps += steps[i];
        }
        ll ans = factorial[total_steps];
        for(ll i=0; i<n; i++) ans = ans*inverse_factorial[steps[i]]%mod;
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    factorial[0] = 1;
    for(ll i=1; i<MAXN; i++) factorial[i] = factorial[i-1]*i%mod;
    inverse_factorial[MAXN-1] = bin_pow(factorial[MAXN-1], mod-2);
    for(ll i=MAXN-2; i>=0; i--) inverse_factorial[i] = inverse_factorial[i+1]*(i+1)%mod;

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