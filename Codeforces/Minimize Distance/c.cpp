// https://codeforces.com/contest/1591/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    ll n, k;
    cin>>n>>k;
    vector<ll> pos, neg;
    for(ll i=0; i<n; i++){
        ll x; cin>>x;
        if(x>0) pos.push_back(x);
        else if(x<0) neg.push_back(abs(x));
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    ll idx = (int)pos.size() - 1;
    ll dist = 0;
    while(idx>=0){
        dist += pos[idx];
        idx -= k;
    }
    idx = (int)neg.size() - 1;
    while(idx >= 0){
        dist += neg[idx];
        idx -= k;
    }
    dist *= 2LL;
    if((int)pos.size() && (int)neg.size()) dist -= max(pos.back(), neg.back());
    else if((int)pos.size()) dist -= pos.back();
    else if((int)neg.size()) dist -= neg.back();
    cout << dist << endl;
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