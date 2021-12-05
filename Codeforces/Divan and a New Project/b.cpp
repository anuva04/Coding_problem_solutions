// https://codeforces.com/contest/1614/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n; cin>>n;
    vector<pair<ll,ll>> visit_idx;
    for(ll i=1; i<=n; i++){
        ll visit; cin>>visit;
        visit_idx.push_back({visit, i});
    }
    sort(visit_idx.begin(), visit_idx.end());
    vector<ll> ans(n+1);
    ans[0] = 0;
    ll dist = 0;
    ll left = -1, right = 1;
    for(ll i=n-1; i>=0; i--){
        ll idx = visit_idx[i].second;
        ll times = visit_idx[i].first;
        // cout << idx << " " << times << endl;
        if(i%2) {
            ans[idx] = left;
            dist += 2*(abs(left)*times);
            left -= 1;
        } else {
            ans[idx] = right;
            dist += 2*(right*times);
            right += 1;
        }
    }
    cout << dist << endl;
    for(auto ele : ans) cout << ele << " "; cout << endl;
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}