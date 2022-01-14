// https://www.spoj.com/problems/LASTDIG/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll binpow(ll a, ll b, ll m){
    ll res = 1;
    a %= m;
    while(b>0){
        if(b&1) res = res * a % m;
        a = a*a%m;
        b >>= 1;
    }
    return res;
}

void solve(){
    ll a, b;
    cin>>a>>b;
    if(a==0 || a==10 || a==20) {
        cout << 0 << endl;
        return;
    }
    if(b==0) {
        cout << 1 << endl;
        return;
    }
    
    ll ans = binpow(a, b, 10);
    cout << ans%10 << endl;
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