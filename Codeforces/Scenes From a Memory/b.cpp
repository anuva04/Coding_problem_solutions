// https://codeforces.com/problemset/problem/1562/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool prime[100];

void solve(string s, int k){
    for(int i=0; i<k; i++){
        if(s[i] == '1' || s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '9'){
            cout << 1 << endl;
            cout << s[i] << endl;
            return;
        }
    }
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            if(!prime[(s[i] - '0') * 10 + (s[j] - '0')]){
                cout << 2 << endl;
                cout << s[i] << s[j] << endl;
                return;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=2; i<100; i++){
        prime[i] = true;
        for(int j=2;j*j<=i; j++){
            if(i%j==0) prime[i] = false;
        }
    }
    ll test; cin>>test;
    while(test--){
        int k; cin>>k;
        string s; cin>>s;
        solve(s, k);
    }
    return 0;
}