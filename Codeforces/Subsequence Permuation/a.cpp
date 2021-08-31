// https://codeforces.com/problemset/problem/1552/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        string s1 = s;
        sort(s1.begin(), s1.end());
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i]!=s1[i]) cnt += 1;
        }
        cout << cnt << endl;
    }
    return 0;
}