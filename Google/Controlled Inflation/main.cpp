// https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000accfdb

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

string getHash(ll i, ll prev){
    return to_string(i) + ":" + to_string(prev);
}

ll solve1(vector<vector<ll>>& v, ll i, ll prev, unordered_map<string, ll>& dp){
    if(i >= v.size()) return 0;
    string key = getHash(i, prev);
    if(dp.find(key) != dp.end()) return dp[key];
    ll mn = *min_element(v[i].begin(), v[i].end());
    ll mx = *max_element(v[i].begin(), v[i].end());
    ll ans = 0;
    if(prev >= mx) {
        ans += (prev - mn);
        ans += solve1(v, i+1, mn, dp);
    } else if(prev <= mn){
        ans += (mx - prev);
        ans += solve1(v, i+1, mx, dp);
    } else {
        ll mnmx = (prev - mn) + (mx - mn) + solve1(v, i+1, mx, dp);
        ll mxmn = (mx - prev) + (mx - mn) + solve1(v, i+1, mn, dp);
        ans = min(mnmx, mxmn);
    }
    return dp[key] = ans;
}

void solve(){
    ll n, p; cin>>n>>p;
    vector<vector<ll>> v(n, vector<ll>(p));
    for(ll i=0; i<n; i++){
        for(ll j=0; j<p; j++) cin>>v[i][j];
    }
    unordered_map<string, ll> dp;
    ll cnt = *max_element(v[0].begin(), v[0].end());
    cnt += solve1(v, 1, cnt, dp);
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll test; cin>>test;
    for(ll t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}