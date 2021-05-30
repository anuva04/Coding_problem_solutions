// https://codeforces.com/problemset/problem/1527/C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        map<ll, vector<ll>> mp;
        for(ll i=1; i<=n; i++){
            ll x; cin>>x;
            mp[x].push_back(i);
        }
        ll ans = 0;
        for(auto ele : mp){
            ll num_similar_ele = ele.second.size();
            ll num_subarr[num_similar_ele];
            num_subarr[num_similar_ele-1] = n-ele.second.back()+1;
            for(ll i=num_similar_ele-2; i>=0; i--){
                num_subarr[i] = num_subarr[i+1] + n - ele.second[i] + 1;
            }
            for(ll i=0; i<num_similar_ele-1; i++){
                ans += (ele.second[i])*(num_subarr[i+1]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}