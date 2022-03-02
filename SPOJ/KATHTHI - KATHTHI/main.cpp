// https://www.spoj.com/problems/KATHTHI/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int r, c; cin>>r>>c;
    vector<string> grid(r);
    for(int i=0; i<r; i++) cin>>grid[i];
    vector<vector<int>> cost(r, vector<int>(c, INF));
    deque<pair<int,int>> q;
    cost[0][0] = 0;
    q.push_back({0,0});
    while(!q.empty()){
        auto cell = q.front();
        q.pop_front();
        
        int x = cell.first, y = cell.second;
        if(x-1>=0){
            if(grid[x][y] == grid[x-1][y]){
                if(cost[x-1][y] > cost[x][y]) {
                    cost[x-1][y] = cost[x][y];
                    q.push_front({x-1, y});
                }
            } else {
                if(cost[x-1][y] > cost[x][y]+1) {
                    cost[x-1][y] = cost[x][y]+1;
                    q.push_back({x-1, y});
                }
            }
        }
        if(x+1<r){
            if(grid[x][y] == grid[x+1][y]){
                if(cost[x+1][y] > cost[x][y]) {
                    cost[x+1][y] = cost[x][y];
                    q.push_front({x+1, y});
                }
            } else {
                if(cost[x+1][y] > cost[x][y]+1) {
                    cost[x+1][y] = cost[x][y]+1;
                    q.push_back({x+1, y});
                }
            }
        }
        if(y-1>=0){
            if(grid[x][y] == grid[x][y-1]){
                if(cost[x][y-1] > cost[x][y]){
                    cost[x][y-1] = cost[x][y];
                    q.push_front({x, y-1});
                }
            } else {
                if(cost[x][y-1] > cost[x][y]+1){
                    cost[x][y-1] = cost[x][y]+1;
                    q.push_back({x, y-1});
                }
            }
        }
        if(y+1<c){
            if(grid[x][y] == grid[x][y+1]){
                if(cost[x][y+1] > cost[x][y]){
                    cost[x][y+1] = cost[x][y];
                    q.push_front({x, y+1});
                }
            } else {
                if(cost[x][y+1] > cost[x][y]+1){
                    cost[x][y+1] = cost[x][y]+1;
                    q.push_back({x, y+1});
                }
            }
        }
    }
    cout << cost[r-1][c-1] << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}