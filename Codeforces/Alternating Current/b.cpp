// https://codeforces.com/contest/343/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(st.empty()) st.push(s[i]);
        else {
            if(st.top() != s[i]) st.push(s[i]);
            else st.pop();
        }
    }
    if(st.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}