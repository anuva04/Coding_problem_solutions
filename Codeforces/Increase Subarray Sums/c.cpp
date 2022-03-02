// https://codeforces.com/contest/1644/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    ll n,x; cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for(ll i=1; i<n; i++) prefix[i] = prefix[i-1]+a[i];
    vector<ll> max_sum_of_len(n+1, LLONG_MIN);
    max_sum_of_len[0] = 0;
    for(ll len=1; len<=n; len++){
        for(ll i=0; i+len-1<n; i++){
            ll sum = prefix[i+len-1];
            if(i-1>=0) sum -= prefix[i-1];
            max_sum_of_len[len] = max(max_sum_of_len[len], sum);
        }
    }
    ll mx = 0;
    for(ll k=0; k<=n; k++){
        for(ll i=k; i<=n; i++) mx = max(mx, max_sum_of_len[i] + k*x);
        cout << mx << ' ';
    }
    cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}