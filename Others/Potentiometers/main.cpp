// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3238

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
    vector<ll> arr;

public:

    BIT(ll n) {
        this->n = n+1;
        bit.assign(n+1, 0);
        arr.assign(n, 0);
    }

    BIT(vector<ll> a) : BIT(a.size()) {
        for(size_t i=0; i<a.size(); i++) {add(i, a[i]); arr[i] = a[i];}
    }

    ll sum(ll i){
        ll ret = 0;
        for(++i; i>0; i -= i & -i) ret += bit[i];
        return ret;
    }

    ll sum(ll l, ll r){
        return sum(r) - sum(l-1);
    }

    void add(ll i, ll delta){
        arr[i] += delta;
        for(++i; i<n; i += i & -i) bit[i] += delta;
    }
};

void solve(ll n){
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin>>arr[i];
    BIT bit(arr);
    while(true){
        string type; cin>>type;
        if(type == "END") return;
        ll x, y; cin>>x>>y;
        if(type == "S"){
            bit.add(x-1, y - arr[x-1]);
            arr[x-1] = y;
        } else {
            ll ans = bit.sum(x-1, y-1);
            cout << endl << ans;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t=0;
    while(++t){
        ll n; cin>>n;
        if(n==0) {
            cout << endl;
            break;
        }
        if(t != 1) cout << endl << endl;
        cout << "Case " << t << ":";
        solve(n);
    }

    // ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}