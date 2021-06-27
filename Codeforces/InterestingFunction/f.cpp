// https://codeforces.com/problemset/problem/1538/F

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin>>t;
    while(t--){
        int l, r;
        cin>>l>>r;
        int ans = 0;
        while(l!=0 || r!=0){
            ans += (r-l);
            r/=10;
            l/=10;
        }
        cout << ans << endl;
    }

    return 0;
}