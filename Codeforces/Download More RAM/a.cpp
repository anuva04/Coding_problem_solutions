// https://codeforces.com/contest/1629/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, k; cin>>n>>k;
    vector<pair<int,int>> reqd_returned(n);
    vector<int> reqd(n);
    for(int i=0; i<n; i++) cin>>reqd[i];
    for(int i=0; i<n; i++){
        int x; cin>>x;
        reqd_returned[i] = {reqd[i], x};
    }
    sort(reqd_returned.begin(), reqd_returned.end());
    for(int i=0; i<n; i++){
        if(reqd_returned[i].first <= k) k += reqd_returned[i].second;
    }
    cout << k << endl;
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