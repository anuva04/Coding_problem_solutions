// https://www.codechef.com/MAY21B/problems/XOREQUAL

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x, ll y){
    ll ans = 1;
    while(y>0){
        if(y%2==1){
            ans = (ans*x)%1000000007;
        }
        y /= 2;
        x = (x*x)%1000000007;
    }
    return ans;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll two = 2;
        ll ans = solve(2, n-1);
        cout << ans << endl;
    }
}