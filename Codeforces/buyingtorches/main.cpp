// https://codeforces.com/problemset/problem/1418/A

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin>>t;
    while(t--){
        ll x,y,k;
        cin>>x>>y>>k;
        ll reqd = y*k + k;
        ll ans = ((reqd-1 + x-1 -1)/(x-1));
        cout<<ans+k<<endl;
    }
    return 0;
}
