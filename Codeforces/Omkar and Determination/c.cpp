// https://codeforces.com/contest/1586/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin>>grid[i];
    vector<int> pre(m, 1);
    for(int c=1; c<m; c++){
        for(int r=1; r<n; r++){
            if(grid[r-1][c]=='X' && grid[r][c-1]=='X'){
                pre[c] = 0;
                break;
            }
        }
    }
    // for(auto ele : pre) cout << ele << " "; cout << endl;
    for(int i=1; i<m; i++) pre[i] += pre[i-1];
    // for(auto ele : pre) cout << ele << " "; cout << endl;
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int c1, c2; cin>>c1>>c2;
        c1-=1; c2-=1;
        if((c2-c1) == (pre[c2] - pre[c1])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}