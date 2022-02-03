// https://codeforces.com/contest/1633/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;

void solve(){
    string s; cin>>s;
    if(s.size() <= 2) {
        cout << 0 << endl;
        return;
    }
    int o = 0, z = 0;
    for(char c : s){
        if(c == '0') z += 1;
        else o += 1;
    }
    if(z < o) cout << z << endl;
    else if(o < z) cout << o << endl;
    else cout << z-1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}