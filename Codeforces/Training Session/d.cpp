// https://codeforces.com/contest/1598/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> t(n), d(n), tf(n+1,0), df(n+1, 0);
    for(int i=0; i<n; i++){
        cin>>t[i]>>d[i];
        tf[t[i]]+=1;
        df[d[i]]+=1;
    }
    ll ans = n*1LL*(n-1)*(n-2)/6;
    for(int i=0; i<n; i++){
        ll remove = (tf[t[i]]-1)*1LL*(df[d[i]]-1);
        ans -= remove;
    }
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