#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int digits(ll n){
    int ans=0;
    while(n>0){
        ans += n%10;
        n = n/10;
    }
    return ans;
}
int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int s; cin>>s;
        if(digits(n) <= s){
            cout << 0 <<endl;
            continue;
        }
        ll ans = 0;
        ll x=1;
        for(int i=1; i<=18; i++){
            int digit = (n/x)%10;
            n += x*((10-digit)%10);
            ans += x*((10-digit)%10);
            if(digits(n)<=s) break;
            x=x*10;
        }
        cout << ans << endl;
    }
    return 0;
}
