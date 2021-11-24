// https://codeforces.com/contest/1605/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    set<string> possibilities = {"aa", "aba", "aca",  "abca", "acba", "abbacca", "accabba"};
    for(int len = 2; len<=7; len++){
        for(int i=0; i<=n-len; i++){
            string s1 = s.substr(i, len);
            // cout << s1 << endl;
            if(possibilities.find(s1) != possibilities.end()){
                cout << len << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
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