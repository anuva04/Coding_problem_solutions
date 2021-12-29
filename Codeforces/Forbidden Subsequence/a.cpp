// https://codeforces.com/contest/1617/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    string t; cin>>t;
    sort(s.begin(), s.end());
    if(t != "abc"){
        cout << s << endl;
        return;
    }
    int a=0, b=0, c=0;
    for(char cc : s){
        if(cc == 'a') a++;
        else if(cc=='b') b++;
        else if(cc=='c') c++;
        else break;
    }
    if(a==0 || b==0 || c==0) {
        cout << s << endl;
        return;
    }
    string s1 = "";
    while(a--) s1 += 'a';
    while(c--) s1 += 'c';
    while(b--) s1 += 'b';
    for(char cc : s){
        if(cc=='a' || cc=='b' || cc=='c') continue;
        s1 += cc;
    }
    cout << s1 << endl;
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