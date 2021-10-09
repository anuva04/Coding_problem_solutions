// https://codeforces.com/contest/1594/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n,k; cin>>n>>k;
    ll power = 1;
    ll ans = 0;
    for(int i=0; i<31; i++){
        if(k&(1<<i)){
            ans += power;
            ans %= mod;
        }
        power *= n;
        power %= mod;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}