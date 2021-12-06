// https://codeforces.com/contest/1561/problem/D2

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> dp(n+1,0);
    vector<ll> prefix(n+1,0);
    ll prev_sum =0 ;
    for(ll i = 1 ; i<= n ; i++){
        if(i == 1){
            prev_sum = 1;
            dp[i] = 1;
            prefix[i] = 1;
            continue;
        }
        prefix[i] += prefix[i-1];
        dp[i] = (prefix[i] + prev_sum)%m;
        dp[i] += (i/2);
        if(i%2 == 1) dp[i]+=1;
        dp[i]--;
        dp[i]%=m;
 
        for(ll a = 2*i,p = 2 ; a <= n ; a += i, p +=1){
            prefix[a] += dp[i];
            prefix[a]%=m;
 
            ll subIndex = a + p;
            if(subIndex <= n) {
                prefix[subIndex] -= dp[i];
                if(prefix[subIndex] < 0) {
                    prefix[subIndex] = ((prefix[subIndex]%m) + m)%m;
                }
            }
        }
        prev_sum += dp[i];
        prev_sum%=m;
        }
    cout << dp[n] << endl;
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}