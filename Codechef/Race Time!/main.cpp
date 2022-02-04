// https://www.codechef.com/problems/AMCS03

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

ld f(ld time, vector<pair<ld,ld>>& sd){
    ld mn = LLONG_MAX, mx = 0;
    for(ll i=0; i<sd.size(); i++){
        mn = min(mn, sd[i].first*time + sd[i].second);
        mx = max(mx, sd[i].first*time + sd[i].second);
    }
    return (mx - mn);
}


void solve(){
    ll n; ld k; cin>>n>>k;
    vector<pair<ld,ld>> sd(n);
    for(ll i=0; i<n; i++) cin>>sd[i].first>>sd[i].second;
    ld left = 0.0, right = k;
    ll turns = 100;
    ld ans = LLONG_MAX;
    while(turns--){
        ld mid1 = left + (right-left)/3;
        ld mid2 = right - (right-left)/3;
        ld ans1 = f(mid1, sd);
        ld ans2 = f(mid2, sd);
        ans = min(ans, min(ans1, ans2));
        if(ans1 < ans2) right = mid2; else left = mid1;
    }
    cout << fixed << setprecision(6) << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}