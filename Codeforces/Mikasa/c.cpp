// https://codeforces.com/contest/1554/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n,m;
    cin>>n>>m;
    m += 1;
    int ans = 0;
    for(int bit = 30; bit>=0; bit--){
        if((n&(1<<bit)) == (m&(1<<bit))) continue;
        if((n&(1<<bit)) && (!(m&(1<<bit)))) break;
        if((!(n&(1<<bit))) && (m&(1<<bit))) ans += (1<<bit);
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}