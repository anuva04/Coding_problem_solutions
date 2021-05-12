// https://www.codechef.com/MAY21B/problems/MODEQ

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t; cin>>t;
    while(t--){
        ll m,n;
        cin>>n>>m;
        ll dp[n+1];
        for(ll i=0; i<=n; i++) dp[i] = 0;
        ll ans=0;
        for(ll a=1; a<=n; a++){
            ans += dp[m%a];
            for(ll b=(m%a); b<=n; b+=a){
                dp[b]+=1;
            }
        }
        cout << ans << endl;
    }
}

// if I divide m by a and get a remainder x, i will increment the count of x
// next time when I divide m by b and get x as remainder, i will know the count of all the other numbers which could give me remainder x
// hence these numbers could form a pair

// now since m%modb is again divided by a, therefore this pattern will repeat after every interval of a, hence we increment mod for all such values of b

// x%1 = 0
// 0%anything = 0

// x%anything = something
// something%1 = 0