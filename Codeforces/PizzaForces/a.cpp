// https://codeforces.com/problemset/problem/1555/A

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
        ll n; cin>>n;
        if(n&1) n+=1;
        n = max(n,6LL);
        ll ans = (n/2)*5;
        cout << ans << endl;
    }
    return 0;
}