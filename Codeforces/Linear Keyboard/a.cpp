// https://codeforces.com/contest/1607/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s, type;
    cin>>s>>type;
    map<char, int> mp;
    int index = 1;
    for(int i=0; i<s.size(); i++){
        mp[s[i]] = index;
        index+=1;
    }
    int ans = 0;
    for(int i=1; i<type.size(); i++){
        ans += abs(mp[type[i]]-mp[type[i-1]]);
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