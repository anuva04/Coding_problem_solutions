// https://codeforces.com/problemset/problem/1541/B

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
        int n; cin>>n;
        vector<ll> a(n+1);
        for(ll i=1; i<=n; i++) cin>>a[i];
        ll cnt = 0;
        for(ll i=1; i<=n; i++){
            for(ll j=a[i]-i; j<=n; j+=a[i]){
                if(j>=0){
                    if(a[i]*a[j] == i+j && i<j) cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}