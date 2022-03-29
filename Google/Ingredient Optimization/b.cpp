// https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a341ecv

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll d, num_orders, reqd; cin>>d>>num_orders>>reqd;
    vector<vector<ll>> leaves;
    ll m, l, e;
    for(ll i=0; i<d; i++){
        cin>>m>>l>>e;
        leaves.push_back({m, l, e});
    }
    sort(leaves.begin(), leaves.end());
    vector<ll> orders(num_orders);
    for(ll i=0; i<num_orders; i++) cin>>orders[i];
    sort(orders.begin(), orders.end());
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;
    ll leaf_idx = 0;
    ll count = 0;
    int i = 0;
    while(i<num_orders){
        ll curr_order = orders[i];
        while((leaf_idx < d) && (leaves[leaf_idx][0] <= curr_order)) {
            q.push({leaves[leaf_idx][0]+leaves[leaf_idx][2], leaves[leaf_idx][1]});
            leaf_idx++;
        }
        while(!q.empty() && q.top().first <= curr_order) q.pop();
        if(q.empty()) break;
        ll rem = reqd;
        while((!q.empty()) && (rem != 0)){
            auto t = q.top();
            q.pop();
            ll x = min(rem, t.second);
            rem -= x;
            t.second -= x;
            if(t.second > 0) q.push({t.first, t.second});
        }
        if(rem == 0) count++;
        else break;
        i++;
    }
    cout << count << "\n";
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