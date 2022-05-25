// https://www.spoj.com/problems/DOSA/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 1e18;

void solve(){
    ll n; cin>>n;
    vector<ll> arr(n), v;
    for(ll i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i] - i > 0){
            v.push_back(arr[i]-i);
        }
    }
    vector<ll> dp(v.size() + 1);
    for(ll i=0; i<=v.size(); i++) dp[i] = INF;
    dp[0] = -INF;
    for(ll i=0; i<v.size(); i++){
        int j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        if(dp[j-1] <= v[i] && v[i] <= dp[j]) dp[j] = v[i];
    }
    ll ans = 0;
    for(ll i=0; i<=v.size(); i++){
        if(dp[i] < INF) ans = i;
    }
    cout << n - ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;

    // for(ll t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
        solve();
    // }
    
    return 0;
}