// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n; cin>>n;
    vector<ll> k(n), h(n);
    for(int i=0; i<n; i++) cin>>k[i];
    for(int i=0; i<n; i++) cin>>h[i];
    vector<pair<ll, ll>> intervals;
    for(int i=0; i<n; i++) intervals.push_back({k[i]-h[i], k[i]});
    sort(intervals.begin(), intervals.end());
    ll ans = 0;
    ll i = -1, j = -1;
    for(auto ele : intervals){
        if(ele.first >= j) {ans += ((j-i)*(j-i+1))/2; i = ele.first, j = ele.second;}
        else j = max(j, ele.second);
    }
    ans += ((j-i)*(j-i+1))/2;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}