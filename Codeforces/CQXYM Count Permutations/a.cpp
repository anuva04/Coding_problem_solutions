// https://codeforces.com/problemset/problem/1581/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll fact[2*100001];
    fact[1] = 1;
    fact[2] = 1;
    for(ll i=3; i<2*100001; i++){
        fact[i] = (i*(fact[i-1]%mod))%mod;
    }
    
    ll test; cin>>test;
    while(test--){
        ll n; cin>>n;
        ll ans = (fact[2*n]%mod);
        cout << ans << endl;
    }
    
    return 0;
}