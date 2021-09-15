// https://codeforces.com/problemset/problem/1540/A

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
        ll n; cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);
        ll ans = arr[n-1];
        ll neg[n];
        neg[0] = 0;
        for(ll i=1; i<n; i++){
            neg[i] = neg[i-1] + (i*(arr[i]-arr[i-1]));
            ans -= neg[i];
        }
        cout << ans << endl;
    }

    return 0;
}