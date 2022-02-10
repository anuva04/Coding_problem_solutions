// https://codeforces.com/contest/1634/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int rows, cols; cin>>rows>>cols;
    if(rows%2 == 1){
        if(cols == 1){
            cout << "YES" << endl;
            for(int i=1; i<=rows*cols; i++) cout << i << endl;
        } else cout << "NO" << endl;
    } else {
        int ans[rows][cols];
        int even = 2;
        for(int r=1; r<rows; r+=2){
            for(int c=0; c<cols; c++) {
                ans[r][c] = even;
                even += 2;
            }
        }
        int odd = 1;
        for(int r=0; r<rows; r+=2){
            for(int c=0; c<cols; c++){
                ans[r][c] = odd;
                odd += 2;
            }
        }
        cout << "YES" << endl;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++) cout << ans[i][j] << ' ';
            cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}