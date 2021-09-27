// https://codeforces.com/problemset/problem/1514/B

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

    ll test; cin>>test;
    while(test--){
        int n, k; cin>>n>>k;
        ll ans = n;
        for(int i=1; i<k; i++){
            ans = (ans*n)%mod;
        }
        cout << ans%mod << endl;
    }
    
    return 0;
}