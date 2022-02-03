// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector<int>> dp;

int dfs(vector<string>& grid, int h, int w, int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    int len = 0;
    if((i+1<h) && (grid[i+1][j] == grid[i][j] + 1)) 
        len = max(len, dfs(grid, h, w, i+1, j));
    if((j+1<w) && (grid[i][j+1] == grid[i][j] + 1)) 
        len = max(len, dfs(grid, h, w, i, j+1));
    if((i-1>=0) && (grid[i-1][j] == grid[i][j] + 1)) 
        len = max(len, dfs(grid, h, w, i-1, j));
    if((j-1>=0) && (grid[i][j-1] == grid[i][j] + 1)) 
        len = max(len, dfs(grid, h, w, i, j-1));
    if((i+1<h && j+1<w) && (grid[i+1][j+1] == grid[i][j] + 1)) 
        len = max(len, dfs(grid, h, w, i+1, j+1));
    if((i+1<h && j-1>=0) && (grid[i+1][j-1] == grid[i][j] + 1))
        len = max(len, dfs(grid, h, w, i+1, j-1));
    if((i-1>=0 && j-1>=0) && (grid[i-1][j-1] == grid[i][j] + 1))
        len = max(len, dfs(grid, h, w, i-1, j-1));
    if((i-1>=0 && j+1<w) && (grid[i-1][j+1] == grid[i][j] + 1))
        len = max(len, dfs(grid, h, w, i-1, j+1));

    return dp[i][j] = len+1;
    
}

void solve(int h, int w){
    dp = vector<vector<int>>(h, vector<int>(w, -1));
    vector<string> grid(h);
    for(int i=0; i<h; i++) cin>>grid[i];
    int ans = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(grid[i][j] == 'A') ans = max(ans, dfs(grid, h, w, i, j));
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    int t = 1;
    while(true){
        int h, w; cin>>h>>w;
        if(h==0 && w==0) break;
        cout << "Case " << t << ": ";
        t++;
        solve(h, w);
    }
    
    return 0;
}