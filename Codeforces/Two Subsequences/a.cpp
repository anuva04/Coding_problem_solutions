// https://codeforces.com/contest/1602/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    char mn = s[0];
    int min_idx = 0;
    for(int i=1; i<s.size(); i++){
        if(s[i] < mn){
            mn = s[i];
            min_idx = i;
        }
    }
    string b = "";
    for(int i=0; i<s.size(); i++){
        if(i==min_idx) continue;
        b += s[i];
    }
    cout << mn << ' ' << b << endl;
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