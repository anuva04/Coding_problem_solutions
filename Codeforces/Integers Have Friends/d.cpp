// https://codeforces.com/contest/1549/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector<ll>> sparse_table(1001, vector<ll>(21));

void build(ll n, vector<ll> dataVector){
    for (ll i = 1;i<=n;i++) sparse_table[i][0] = dataVector[i];

    for (int j = 1;j<=20;j++){
        for (int i = 1;i + (1<<j) <= n + 1;i++){
            sparse_table[i][j] = __gcd(sparse_table[i][j - 1],
                sparse_table[i + (1<<(j - 1))][j - 1]);
        }
    }
}

ll query(ll l, ll r, vector<ll> dataVector){
    ll val = dataVector[l];
    for (int j = 20;j>=0;j--){
        if ((1<<j) <= r - l + 1){
            val = __gcd(val,sparse_table[l][j]);
            l += (1<<j);
        }
    }
    return val;
}

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
        vector<ll> a(n+1);
        
        for(ll i=1; i<=n; i++) cin>>a[i];
        vector<ll> diff(n+1);
        for(ll i=1; i<=n; i++) diff[i] = a[i] - a[i-1];

        sparse_table.clear();
        sparse_table.resize(n+1, vector<ll>(21));
        build(n, diff);

        ll left = 1, right = n, ans = 1;
        while(left <= right){
            ll mid = (left+right)/2;
            bool possible = false;
            for(ll i=1; i<=n-mid+1; i++){
                ll l = i+1, r=i+mid-1;
                // ll gcd = query(l, r, diff);
                ll val = diff[l];
                for (int j = 20;j>=0;j--){
                    if ((1<<j) <= r - l + 1){
                        val = __gcd(val,sparse_table[l][j]);
                        l += (1<<j);
                    }
                }
                if(abs(val)>1 || val==0){
                    possible = true;
                    break;
                }
            }
            if(possible){
                ans = mid;
                left = mid+1;
            } else  right = mid-1;
        }
        cout << ans << endl;
    }
    
    return 0;
}