// https://codeforces.com/contest/1554/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    if(n==1){ cout << 'a' << endl; return;}
    string ans = "";
    int len = n/2;
    for(int i=0; i<len; i++) ans += 'x';
    ans += 'y';
    len -= 1;
    for(int i=0; i<len; i++) ans += 'x';
    if(n&1) ans += 'z';
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