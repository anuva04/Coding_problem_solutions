// https://codeforces.com/problemset/problem/1600/J

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

int dfs(vector<vector<int>>& room, vector<vector<bool>>& visited, int i, int j){
    if(i<0 || j<0 || i>=room.size() || j>=room[0].size() || visited[i][j]) return 0;
    int ans = 1;
    visited[i][j] = true;
    if(!((room[i][j]>>3)&1)) ans += dfs(room, visited, i-1, j); // north
    if(!((room[i][j]>>1)&1)) ans += dfs(room, visited, i+1, j); // south
    if(!((room[i][j])&1)) ans += dfs(room, visited, i, j-1); // west
    if(!((room[i][j]>>2)&1)) ans += dfs(room, visited, i, j+1); // east
    return ans;
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> room(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin>>room[i][j];
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            int area = dfs(room, visited, i, j);

            // for(int a=0; a<n; a++){
            //     for(int b=0; b<m; b++) cout << (visited[a][b] ? 1 : 0) << ' ';
            //     cout << endl;
            // }
            // cout << endl;

            if(area) ans.push_back(area);
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(auto ele : ans) cout << ele << ' '; cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}