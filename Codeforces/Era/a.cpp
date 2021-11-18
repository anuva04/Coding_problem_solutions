// https://codeforces.com/contest/1604/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];
    int shift = 0;
    for(int i=1; i<=n; i++){
        if(arr[i]<=i+shift) continue;
        shift += (arr[i]-(i+shift));
    }
    cout << shift << endl;
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