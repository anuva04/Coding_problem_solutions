// https://www.spoj.com/problems/WATER/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int rows, cols; cin>>rows>>cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for(int r=0; r<rows; r++) for(int c=0; c<cols; c++) cin>>mat[r][c];

    if(rows <= 2 || cols <= 2){
        cout << 0 << endl;
        return;
    }

    int ans = 0, maxH = 0;

    priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>> >, greater< pair<int, pair<int,int>> > > bfs;
    for(int c=0; c<cols; c++) {
        bfs.push({mat[0][c], {0, c}});
        visited[0][c] = true;
        bfs.push({mat[rows-1][c], {rows-1, c}});
        visited[rows-1][c] = true;
    }
    for(int r=1; r<rows-1; r++){
        bfs.push({mat[r][0], {r, 0}});
        visited[r][0] = true;
        bfs.push({mat[r][cols-1], {r, cols-1}});
        visited[r][cols-1] = true;
    }

    while(!bfs.empty()){
        auto ele = bfs.top();
        bfs.pop();
        int height = ele.first;
        int r = ele.second.first;
        int c = ele.second.second;

        maxH = max(maxH, height);
        if(r+1<rows){
            if(!visited[r+1][c]){ 
                bfs.push({mat[r+1][c], {r+1, c}});
                if(mat[r+1][c] < maxH) ans += (ans, maxH - mat[r+1][c]);
                visited[r+1][c] = true;
            }
        }
        if(r-1 >= 0){
            if(!visited[r-1][c]){ 
                bfs.push({mat[r-1][c], {r-1, c}});
                if(mat[r-1][c] < maxH) ans += (ans, maxH - mat[r-1][c]);
                visited[r-1][c] = true;
            }
        }
        if(c+1 < cols){
            if(!visited[r][c+1]){ 
                bfs.push({mat[r][c+1], {r, c+1}});
                if(mat[r][c+1] < maxH) ans += (ans, maxH - mat[r][c+1]);
                visited[r][c+1] = true;
            }
        }
        if(c-1 >= 0){
            if(!visited[r][c-1]){ 
                bfs.push({mat[r][c-1], {r, c-1}});
                if(mat[r][c-1] < maxH) ans += (ans, maxH - mat[r][c-1]);
                visited[r][c-1] = true;
            }
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
    
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}