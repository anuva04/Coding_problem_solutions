// https://codeforces.com/contest/1614/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n,l,r,k; cin>>n>>l>>r>>k;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i]<l) continue;
        if(a[i]>r) break;
        if(k-a[i]>=0){
            cnt += 1;
            k -= a[i];
        } else break;
    }
    cout << cnt << endl;
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