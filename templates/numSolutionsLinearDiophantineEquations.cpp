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

// Equation of the form:
// n1*x + n2*y = n

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