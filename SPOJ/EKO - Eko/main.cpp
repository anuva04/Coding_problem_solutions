// https://www.spoj.com/problems/EKO/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    ll n, reqd;
    cin>>n>>reqd;
    vector<ll> heights(n);
    for(ll i=0; i<n; i++) cin>>heights[i];
    ll h = *max_element(heights.begin(), heights.end()), l = 0, ans = 0;
    while(l <= h){
        ll m = l + (h-l)/2;
        ll wood = 0;
        for(ll i=0; i<n; i++) wood += (max(0LL, heights[i] - m));
        if(wood == reqd) {ans = m; break;}
        else if(wood < reqd) h = m-1;
        else {
            l = m+1;
            ans = max(ans, m);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}