// https://codeforces.com/contest/1504/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    if((n&1)!=0 || s[0]=='0' || s[n-1]=='0'){
        cout << "NO" << endl;
        return;
    }
    int zeros = 0, ones = 0;
    for(char c : s){
        if(c =='0') zeros += 1;
        else ones += 1;
    }
    if((zeros&1)!=0 || (ones&1)!=0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    string s1 = "", s2 = "";
    int cnt1 = 0, cnt2 = 0;
    int curr_ones = 1;
    bool turn = true;
    for(int i=0; i<n; i++){
        if(s[i] == '1'){
            if(curr_ones <= ones/2){
                s1 += '(';
                s2 += '(';
            } else {
                s1 += ')';
                s2 += ')';
            }
            curr_ones += 1;
        } else {
            if(turn){
                s1 += '(';
                s2 += ')';
            } else {
                s1 += ')';
                s2 += '(';
            }
            turn = !turn;
        }
    }
    cout << s1 << endl;
    cout << s2 << endl;
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