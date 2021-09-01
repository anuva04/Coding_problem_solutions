// https://codeforces.com/problemset/problem/1553/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(string s, string t){
    if(s.size()<t.size()) {cout << "NO" << endl; return;}
    else {
        int s_idx = s.size()-1;
        int t_idx = t.size()-1;
        while(s_idx>=0 && t_idx>=0){
            if(s[s_idx] == t[t_idx]){
                s_idx-=1;
                t_idx-=1;
            }else{
                s_idx-=2;
            }
            if(t_idx < 0){ cout << "YES" << endl; return;}
        }
        cout << "NO" << endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        string s,t; cin>>s>>t;
        solve(s,t);
    }
    return 0;
}