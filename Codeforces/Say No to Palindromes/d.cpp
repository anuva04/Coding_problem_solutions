// https://codeforces.com/contest/1560/problem/E

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int test; cin>>test;
    // while(test--){
        
    // }
    int n, m; cin>>n>>m;
    string s; cin>>s;
    string t = "abc";
    vector<vector<int>> dp(6, vector<int>(n+1));
    for(int i=0; i<6; i++){
        // cout << t << endl;
        for(int j=0; j<n; j++){
            dp[i][j+1] = dp[i][j] + (s[j] != t[j%3]);
        }
        next_permutation(t.begin(), t.end());
    }
    // for(int i=0; i<6; i++){
    //   for(int j=0; j<n; j++){
    //       cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    while(m--){
        int l,r; cin>>l>>r;
        int ans = INT_MAX;
        for(int i=0; i<6; i++){
            ans = min(ans, dp[i][r]-dp[i][l-1]);
        }
        cout << ans << endl;
    }
    return 0;
}