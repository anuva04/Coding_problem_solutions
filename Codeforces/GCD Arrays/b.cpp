// https://codeforces.com/contest/1629/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int l, r, k;
    cin>>l>>r>>k;
    if(l==r){
        if(l==1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }
    int num_odd = (r - l + 1)/2;
    if(((r - l + 1)%2 != 0) && (l%2 != 0)) num_odd += 1;
    if(num_odd <= k) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}