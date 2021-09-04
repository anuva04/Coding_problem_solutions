// https://codeforces.com/problemset/problem/1547/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        ll x[n];
        vector<ll> y(n, 0);
        y[0] = 0;
        for(int i=0; i<n; i++) cin>>x[i];
        for(int i=1; i<n; i++){
            ll t = y[i-1]^x[i-1];
            y[i] = ((t|x[i])^x[i]);
        }
        for(auto ele : y) cout << ele << " ";
        cout << endl;
    }
    return 0;
}