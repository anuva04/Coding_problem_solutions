// https://codeforces.com/contest/1594/problem/E1

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

void solve(){
    int k; cin>>k;
    ll num_nodes = (1LL<<k)-1;
    ll ans1 = power(4,num_nodes-1,mod);
    ll ans = (6*ans1);
    ans %= mod;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    
    return 0;
}