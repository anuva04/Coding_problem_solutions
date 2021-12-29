// https://codeforces.com/contest/1617/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    if(n&1){
        if((n/2)&1) cout  << n/2 - 2 << ' ' << n/2 + 2 << ' ' << 1 << endl; 
        else cout  << n/2 - 1 << ' ' << n/2 + 1 << ' ' << 1 << endl;
    } else cout  << n/2 - 1 << ' ' << n/2 << ' ' << 1 << endl;
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