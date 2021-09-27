// https://codeforces.com/problemset/problem/1573/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        ll n; cin>>n;
        vector<ll> odd(n), even(n);
        for(ll i=0; i<n; i++) cin>>odd[i];
        for(ll i=0; i<n; i++) cin>>even[i];

        unordered_map<ll,ll> oddNum_evenIdx_pair;
        ll oddNum = 1;
        for(ll i=0; i<n; i++){
            while(oddNum < even[i]){
                oddNum_evenIdx_pair[oddNum] = i;
                oddNum += 2;
            }
        }
        
        ll ans = 1e18;
        for(ll i=0; i<n; i++){
            ans = min(ans, i+oddNum_evenIdx_pair[odd[i]]);
        }

        cout << ans << endl;
    }
    
    return 0;
}