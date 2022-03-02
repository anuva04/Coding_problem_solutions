// https://codeforces.com/contest/1063/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n, m; cin>>n>>m;
    int r, c; cin>>r>>c; r-=1, c-=1;
    int x, y; cin>>x>>y;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin>>grid[i];
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    deque<vector<int>> q;
    visited[r][c] = 1;
    q.push_back({r, c, 0, 0});
    int cnt = 0;
    while(!q.empty()){
        auto cell = q.front();
        q.pop_front();
        cnt++;

        int curr_r = cell[0], curr_c = cell[1], curr_x = cell[2], curr_y = cell[3];

        if(curr_r-1 >= 0 && !visited[curr_r-1][curr_c] && grid[curr_r-1][curr_c] != '*' && curr_x<=x && curr_y<=y){
            visited[curr_r-1][curr_c] = 1;
            q.push_front({curr_r-1, curr_c, curr_x, curr_y});
        }

        if(curr_r+1 < n && !visited[curr_r+1][curr_c] && grid[curr_r+1][curr_c] != '*' && curr_x<=x && curr_y<=y){
            visited[curr_r+1][curr_c] = 1;
            q.push_front({curr_r+1, curr_c, curr_x, curr_y});
        }

        if(curr_c-1>=0 && !visited[curr_r][curr_c-1] && grid[curr_r][curr_c-1] != '*' && curr_x+1<=x && curr_y<=y){
            visited[curr_r][curr_c-1] = 1;
            q.push_back({curr_r, curr_c-1, curr_x+1, curr_y});
        }

        if(curr_c+1<m && !visited[curr_r][curr_c+1] && grid[curr_r][curr_c+1] != '*' && curr_x<=x && curr_y+1<=y){
            visited[curr_r][curr_c+1] = 1;
            q.push_back({curr_r, curr_c+1, curr_x, curr_y+1});
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++) cout << visited[i][j] << ' ';
    //     cout << endl;
    // }
    cout << cnt << endl;
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