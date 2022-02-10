// https://codeforces.com/problemset/problem/1494/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    string s; cin>>s;
    int a=0, b=0, c=0;
    for(char cc : s){
        if(cc == 'A') a++;
        else if(cc == 'B') b++;
        else c++;
    }
    if(a+b == c){
        for(char& cc : s){
            if(cc == 'A' || cc == 'B') cc = '0';
            else cc = '1';
        }
    } else if(b+c == a){
        for(char& cc : s){
            if(cc == 'B' || cc == 'C') cc = '0';
            else cc = '1';
        }
    } else if(c+a == b){
        for(char& cc : s){
            if(cc == 'C' || cc == 'A') cc = '0';
            else cc = '1';
        }
    } else {
        cout << "no" << endl;
        return;
    }
    char opening;
    if(s[0] == '0') opening = '0';
    else opening = '1';
    int cnt = 0;
    for(char cc : s){
        if(cc == opening) cnt++;
        else cnt--;
        if(cnt < 0) {
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}