// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    int n = s.size();
    for(int i=n-1; i>=1; i--){
        string s1 = s.substr(i-1, 2);
        int x = stoi(s1);
        int nx = 0;
        int x1 = x;
        while(x1){
            int dig = x1%10;
            nx += dig;
            x1 /= 10;
        }
        // cout << x << ' ' << nx << endl;
        if(nx>=10){
            string ns = "";
            for(int j=0; j<i-1; j++) ns += s[j];
            ns += to_string(nx);
            for(int j=i+1; j<n; j++) ns += s[j];
            cout << ns << endl;
            return;
        }
    }
    string s1 = s.substr(0,2);
    // cout << s1 << endl;
    int x = stoi(s1);
    int nx = 0;
    int x1 = x;
    while(x1){
        int dig = x1%10;
        nx += dig;
        x1 /= 10;
    }
    string ns = to_string(nx);
    for(int j=2; j<n; j++) ns += s[j];
    cout << ns << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}