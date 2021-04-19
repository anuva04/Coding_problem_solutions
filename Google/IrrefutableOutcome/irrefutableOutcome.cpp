// https://codingcompetitions.withgoogle.com/codejamio/round/00000000004360f2/0000000000777c68

#include <bits/stdc++.h>
using namespace std;

int solve(string b, int i, int j, bool iza, vector<vector<int>> &dp){
    // String has a minimum length of 2
    // i.e. initially i<j
    // at next turn (Olga's turn) i=j
    // next turn (Iza's turn) i>j, but this means string is empty
    // Hence Iza has no legal move and hence loses
    if(i>j) return 1;
    
    if(dp[i][j] != INT_MAX) return dp[i][j];
    
    int ans = 0;
    
    if(iza){
        if(b[i]=='I' && b[j]=='I'){
            int ans1 = solve(b, i+1, j, false, dp);
            int ans2 = solve(b, i, j-1, false, dp);
            ans = max(ans1, ans2);
        }else if(b[i]=='I'){
            ans = solve(b, i+1, j, false, dp);
        }else if(b[j]=='I'){
            ans = solve(b, i, j-1, false, dp);
        }else {
            return dp[i][j] = (j-i+2);
        }
    } else {
        if(b[i]=='O' && b[j]=='O'){
            int ans1 = solve(b, i+1, j, true, dp);
            int ans2 = solve(b, i, j-1, true, dp);
            ans = max(ans1, ans2);
        }else if(b[i]=='O'){
            ans = solve(b, i+1, j, true, dp);
        }else if(b[j]=='O'){
            ans = solve(b, i, j-1, true, dp);
        }else {
            return dp[i][j] = (j-i+2);
        }
    }
    return dp[i][j] = -ans;
}

int main(){
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        string b; cin>>b;
        int n = b.length();
        cout << "Case #" << tt << ": ";
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        int ans = solve(b, 0, n-1, true, dp);
        if(ans < 0) cout << "I " << abs(ans) << endl;
        else cout << "O " << ans << endl;
    }
}