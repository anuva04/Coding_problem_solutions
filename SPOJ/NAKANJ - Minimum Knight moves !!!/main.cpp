// https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int board[8][8];
    memset(board, -1, sizeof board);
    string start, destination; cin>>start>>destination;
    int x1 = start[0] - 'a';
    int y1 = start[1] - '0' - 1;
    int x2 = destination[0] - 'a';
    int y2 = destination[1] - '0' - 1;
    // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

    board[x1][y1] = 0;
    queue<pair<int,int>> bfs;
    bfs.push({x1, y1});

    while(!bfs.empty()){
        auto ele = bfs.front();
        bfs.pop();
        int x = ele.first, y = ele.second;
        if(x == x2 && y == y2){
            cout << board[x2][y2] << endl;
            return;
        }
        if(x+2<8 && y+1<8 && board[x+2][y+1] == -1){
            board[x+2][y+1] = board[x][y] + 1;
            bfs.push({x+2, y+1});
        }
        if(x+1<8 && y+2<8 && board[x+1][y+2] == -1){
            board[x+1][y+2] = board[x][y] + 1;
            bfs.push({x+1, y+2});
        }
        if(x-1>=0 && y+2<8 && board[x-1][y+2] == -1){
            board[x-1][y+2] = board[x][y] + 1;
            bfs.push({x-1, y+2});
        }
        if(x-2>=0 && y+1<8 && board[x-2][y+1] == -1){
            board[x-2][y+1] = board[x][y] + 1;
            bfs.push({x-2, y+1});
        }
        if(x-2>=0 && y-1>=0 && board[x-2][y-1] == -1){
            board[x-2][y-1] = board[x][y] + 1;
            bfs.push({x-2, y-1});
        }
        if(x-1>=0 && y-2>=0 && board[x-1][y-2] == -1){
            board[x-1][y-2] = board[x][y] + 1;
            bfs.push({x-1, y-2});
        }
        if(x+1<8 && y-2>=0 && board[x+1][y-2] == -1){
            board[x+1][y-2] = board[x][y] + 1;
            bfs.push({x+1, y-2});
        }
        if(x+2<8 && y-1>=0 && board[x+2][y-1] == -1){
            board[x+2][y-1] = board[x][y] + 1;
            bfs.push({x+2, y-1});
        }
    }
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