// https://codeforces.com/contest/1504/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool isPalindrome(string& s){
    int i = 0, j = s.size()-1;
    while(i<=j){
        if(s[i] != s[j]) return false;
        i+=1, j-=1;
    }
    return true;
}

void solve(){
    string s; cin>>s;
    bool otherChar = false;
    for(char c : s) {
        if(c != 'a'){
            otherChar = true;
            break;
        }
    }
    if(!otherChar) cout << "NO" << endl;
    else {
        string s1 = s;
        s1 += 'a';
        if(!isPalindrome(s1)){
            cout << "YES" << endl;
            cout << s1 << endl;
            return;
        }
        s1 = s;
        s1.insert(0, 1, 'a');
        cout << "YES" << endl;
        cout << s1 << endl;
    }
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