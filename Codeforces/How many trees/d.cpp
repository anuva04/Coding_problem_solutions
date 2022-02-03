// http://codeforces.com/problemset/problem/9/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;


void solve(){
    ll N, H;
    cin>>N>>H;
    ll dp[N+1][N+1];

    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(ll i=1; i<=N; i++) dp[0][i] = 0;
    for(ll i=1; i<=N; i++) dp[i][0] = 0;

    for(ll n=1; n<=N; n++){
        for(ll h=1; h<=N; h++){
            for(ll m=1; m<=n; m++){
                ll term1 = 0;
                for(ll i=0; i<=h-1; i++) term1 += dp[n-m][i];
                term1 *= dp[m-1][h-1];

                ll term2 = 0;
                for(ll i=0; i<=h-2; i++) term2 += dp[m-1][i];
                term2 *= dp[n-m][h-1];

                dp[n][h] += (term1 + term2);
            }
        }
    }

    // for(ll i=0; i<=N; i++){
    //     for(ll j=0; j<=N; j++) cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    ll ans = 0;
    for(ll i=H; i<=N; i++) ans += dp[N][i];
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}