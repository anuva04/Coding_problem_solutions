// https://codeforces.com/contest/1598/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int cols; cin>>cols;
    
    int rows = 2;
    vector<string> maze(2);
    
    for(int i=0; i<2; i++){
        cin>>maze[i];
    }
    
    for(int i=0; i<cols; i++){
        if(maze[0][i]=='1' && maze[1][i]=='1'){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}