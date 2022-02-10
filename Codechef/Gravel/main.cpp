// https://www.codechef.com/problems/SPREAD

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

class BIT {
    vector<ll> bit;
    ll n;

public:

    BIT(ll n) {
        this->n = n+1;
        bit.assign(n+1, 0);
    }

    void add(ll idx, ll val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(ll l, ll r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }

    ll point_query(ll idx) {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

};

void solve(){
    ll n, m, c; cin>>n>>m>>c;
    BIT bit(n);
    while(m--){
        char type; cin>>type;
        if(type == 'Q'){
            ll idx; cin>>idx;
            ll ans = c + bit.point_query(idx-1);
            cout << ans << endl;
        } else {
            ll u, v, k; cin>>u>>v>>k;
            bit.range_add(u-1, v-1, k);
        }
    }
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}