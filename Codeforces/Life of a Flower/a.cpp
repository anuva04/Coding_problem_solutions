// https://codeforces.com/contest/1591/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    int height = 1;
    cin>>a[0];
    if(a[0] == 1) height += 1;
    for(int i=1; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<n; i++){
        if(a[i]==0 && a[i-1]==0){
            cout << -1 << endl;
            return;
        } else if(a[i]==0) continue;
        else {
            height += 1;
            if(a[i-1]==1) height += 4;
        }
    }
    cout << height << endl;
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