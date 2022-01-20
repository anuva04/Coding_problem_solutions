// https://codeforces.com/contest/1609/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n; cin>>n;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin>>arr[i];
    ll k = 0;
    for(ll i=0; i<n; i++){
        while(!(arr[i]&1)){
            arr[i] /= 2;
            k += 1;
        }
    }
    sort(arr.begin(), arr.end());
    arr[n-1] *= pow(2, k);
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    cout << sum << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}