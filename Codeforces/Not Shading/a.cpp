// https://codeforces.com/contest/1627/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, m, r, c;
    cin>>n>>m>>r>>c;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin>>grid[i];
    // cout << grid[0] << endl;
    if(grid[r-1][c-1]=='B') cout << 0 << endl;
    else {
        for(int i=0; i<m; i++) {
            if(grid[r-1][i]=='B'){
                cout << 1 << endl;
                return;
            }
        }
        for(int i=0; i<n; i++){
            if(grid[i][c-1]=='B'){
                cout << 1 << endl;
                return;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='B'){
                    cout << 2 << endl;
                    return;
                }
            }
        }
        cout << -1 << endl;
        return;
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