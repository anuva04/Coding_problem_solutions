// https://codeforces.com/problemset/problem/1547/E

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
        ll n,k; cin>>n>>k;
        vector<ll> a(k);
        for(ll i=0;  i<k; i++) cin>>a[i];
        vector<ll> temp(k);
        for(ll i=0; i<k; i++) cin>>temp[i];
        vector<ll> pos(n, INT_MAX);
        for(ll i=0; i<k; i++){
            pos[a[i]-1] = temp[i];
        }
        ll dp = INT_MAX;
        vector<ll> from_left(n, INT_MAX);
        for(ll i=0; i<n; i++){
            dp = min(dp+1, pos[i]);
            from_left[i] = dp;
        }
        vector<ll> from_right(n, INT_MAX);
        dp = INT_MAX;
        for(ll i=n-1; i>=0; i--){
            dp = min(dp+1, pos[i]);
            from_right[i] = dp;
        }
        for(ll i=0; i<n; i++) cout << min(from_left[i], from_right[i]) << " ";
        cout << endl;
    }

    return 0;
}