// https://codeforces.com/problemset/problem/835/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1]) dp[i][i+1] = 2;
    }
    for(int len=3; len<=n; len++){
        for(int i=0; i<n; i++){
            int j = i+len-1;
            if(j>=n) break;
            if((s[i] != s[j]) || (dp[i+1][j-1] == 0)) continue;
            int mid = (i+j)/2;
            if(!((i+j)&1)) mid -= 1;
            dp[i][j] = 1 + dp[i][mid];
        }
    }
    vector<int> ans(n+1,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) ans[dp[i][j]]++;
    }
    for(int i=n-1; i>=0; i--) ans[i] += ans[i+1];
    for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}