// https://codeforces.com/contest/1582/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    ll zeros = 0, ones = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(x==0) zeros += 1;
        if(x==1) ones += 1;
    }
    if(ones == 0){
        cout << 0 << endl;
        return;
    }
    ll ans = (1LL<<zeros);
    ans *= ones;
    cout << ans << endl;
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