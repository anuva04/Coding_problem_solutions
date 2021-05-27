// https://codeforces.com/problemset/problem/1519/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int dp[102][102];
    dp[1][1] = 0;

    for(int i=2; i<=101; i++){
        dp[1][i] = dp[1][i-1] + 1;
        dp[i][1] = dp[i-1][1] + 1;
    }
    
    for(int i=2; i<=101; i++){
        for(int j=2; j<=101; j++){
            dp[i][j] = dp[i][j-1] + i;
        }
    }

    // for(int i=1; i<=10; i++){
    //     for(int j=1; j<=10; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int t; cin>>t;
    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        if(dp[n][m]==k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}