// https://www.spoj.com/problems/KOPC12A/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

ll cost_function(ll h, vector<ll>& heights, vector<ll>& cost){
    ll ans = 0;
    for(ll i=0; i<heights.size(); i++){
        ans += cost[i]*(abs(h - heights[i]));
    }
    return ans;
}

void solve(){
    ll n; cin>>n;
    vector<ll> heights(n);
    for(ll i=0; i<n; i++) cin>>heights[i];
    vector<ll> cost(n);
    for(ll i=0; i<n; i++) cin>>cost[i];

    ll left = 0, right = 10000;
    ll turns = 200;

    ll ans = LLONG_MAX;
    while(turns--){
        ll mid1 = left + (right-left)/3;
        ll mid2 = right - (right-left)/3;
        ll ans1 = cost_function(mid1, heights, cost);
        ll ans2 = cost_function(mid2, heights, cost);
        ans = min(ans, min(ans1, ans2));
        if(ans1 < ans2) right = mid2; else left = mid1;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}