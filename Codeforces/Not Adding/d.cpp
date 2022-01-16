// https://codeforces.com/contest/1627/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    int x;
    int sz = 1e6 + 5;
    vector<bool> arr(sz, false);
    for(int i=0; i<n; i++){
        cin>>x;
        arr[x] = true;
    }
    int cnt = 0;
    for(int i=1; i<sz; i++){
        if(arr[i]) continue;
        int g = 0;
        for(int k=2; k*i<sz; k++){
            if(arr[k*i]) g = __gcd(g, k*i);
        }
        if(g == i) cnt++;
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}