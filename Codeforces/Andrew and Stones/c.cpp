// https://codeforces.com/contest/1637/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    if(n == 3){
        if(a[1]%2 == 1) {
            cout << -1 << endl;
        } else {
            ll ans = (a[1]/2);
            cout << ans << endl;
        }
        return;
    }
    bool allOnes = true;
    for(ll i=1; i<n-1; i++){
        if(a[i] != 1) allOnes = false;
    }
    if(allOnes) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for(ll i=1; i<n-1; i++){
        if(a[i]%2 == 0) ans += (a[i]/2);
        else ans += ((a[i]+1)/2);
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}