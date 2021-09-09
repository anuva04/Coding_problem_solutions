// https://codeforces.com/problemset/problem/1498/B

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
        ll n, w; cin>>n>>w;
        multiset<ll> rect;
        for(ll i=0; i<n; i++){
            ll x; cin>>x;
            rect.insert(x);
        }
        ll height = 1;
        ll rem_width = w;
        ll i=0;
        while(rect.size()>0){
            auto it = rect.upper_bound(rem_width);
            if(it == rect.begin()){
                height += 1;
                rem_width = w;
            } else {
                it--;
                int val = *it;
                rem_width -= val;
                rect.erase(it);
            }
        }
        cout << height << endl;
    }

    return 0;
}