// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];  

    int a2plusb2 = 0, total = 0;
    for(int i=0; i<n; i++) a2plusb2 += (a[i]*a[i] + b[i]*b[i]), total += (a[i]+b[i]);

    vector<bitset<100001>> dp(2);
    dp[0][a[0]] = dp[0][b[0]] = 1;
    for(int i = 1; i < n; i++){
        dp[i%2].reset();
        for(int sum=1; sum<=10000; sum++){
            if(sum - a[i] >= 0) dp[i%2][sum] = dp[i%2][sum]|dp[(i-1)%2][sum - a[i]];
            if(sum - b[i] >= 0) dp[i%2][sum] = dp[i%2][sum]|dp[(i-1)%2][sum - b[i]];
        }
    }

    int ans = INT_MAX;
    for(int asum=1; asum<=10000; asum++){
        if(dp[(n-1)%2][asum]){
            int bsum = total - asum;
            ans = min(ans, asum*asum + bsum*bsum);
        }
    }

    cout << ans + (n-2)*a2plusb2 << endl;
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