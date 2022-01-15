// https://codeforces.com/contest/1612/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll sumFirstN(ll x){
    return x * 1LL * (x+1) / 2;
}

void solve(){
    ll k, x; cin>>k>>x;
    ll l = 1, r = 2*k-1;
    ll ans = 2*k - 1;
    while(l<=r){
        ll mid = (l+r)>>1;
        ll msgs;
        if(mid>=k){
            msgs = sumFirstN(k) + sumFirstN(k-1) - sumFirstN(2*k - 1 - mid);
        } else msgs = sumFirstN(mid);
        if(msgs >= x){
            ans = mid;
            r = mid-1;
        } else l = mid+1;
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