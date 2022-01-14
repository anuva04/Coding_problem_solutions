// https://codeforces.com/contest/1612/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int x, y; cin>>x>>y;
    int dist = x+y;
    for(int i = 0; i<=dist; i++){
        int j = dist/2 - i;
        if(dist/2 == abs(x-i)+abs(y-j)){
            cout << i << ' ' << j << endl;
            return;
        }
    }
    cout << -1 << ' ' << -1 << endl;
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}