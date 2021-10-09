#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll power(ll a, ll b, ll p){
    if(b == 0){
        return 1;
    }
    ll res = power(a,b/2,p);
    res *= res;
    res %= p;
    if(b % 2){
        res *= a;
    }
    return res % p;
}