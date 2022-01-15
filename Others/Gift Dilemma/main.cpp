// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4628

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll extendedGCD(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extendedGCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

ll numSolutionsLinearDiophantineEquations(ll n1, ll n2, ll n){
    ll a, b, g;
    g = extendedGCD(n1, n2, a, b);
    if(n%g != 0) return 0;
    ll k = n/g, k1, k2;
    a *= k, b *= k;
    k1 = n1*n2/g/n1, k2 = n1*n2/g/n2;
    if(a<0){
        k = -(a/k1) + (a%k1 != 0);
        a += k*k1, b -= k*k2;
    }
    if(b<0){
        k = -(b/k2) + (b%k2 != 0);
        a -= k*k1, b += k*k2;
    }
    if(a < 0 || b < 0) return 0;

    ll x1, x2, y1, y2;
    k = a/k1;
    a -= k*k1;
    b += k*k2;
    x1 = a, y1 = b;

    k = b/k2;
    a += k*k1;
    b -= k*k2;
    x2 = a, y2 = b;

    return (x2 - x1) / k1 + 1;
}

void solve(){
    ll a, b, c, p;
    cin>>a>>b>>c>>p;
    ll ans = 0, x, y;
    ll g = extendedGCD(extendedGCD(a, b, x, y), c, x, y);
    p/=g, a/=g, b/=g, c/=g;
    for(ll i=0; p-c*i>=0; i++){
        ans += numSolutionsLinearDiophantineEquations(a, b, p-c*i);
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    for(int t=1; t<=test; t++){
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}