// https://codeforces.com/contest/1513/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int minn = *min_element(a.begin(), a.end());
    int cnt_min = 0;
    for(int i=0; i<n; i++){
        if((minn&a[i]) != minn) {
            cout << 0 << endl;
            return;
        }
        if(minn == a[i]) cnt_min += 1;
    }
    if(cnt_min<2){
        cout << 0 << endl;
        return;
    }
    int factorial = 1;
    for(int i=2; i<=n-2; i++) factorial = (factorial*1LL*i)%mod;
    int ans = (1LL * cnt_min * (cnt_min-1))%mod;
    ans = (ans*1LL*factorial)%mod;
    cout << ans << endl;
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
        solve();
    }
    
    return 0;
}