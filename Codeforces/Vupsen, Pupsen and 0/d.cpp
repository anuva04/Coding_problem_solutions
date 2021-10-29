// https://codeforces.com/contest/1582/problem/D

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
    vector<int> b(n);
    if(n%2 == 0){
        for(int i=1; i<n; i+=2){
            b[i-1] = -a[i];
            b[i] = a[i-1];
        }
    } else {
        if(a[0]+a[1] != 0) b[0] = -a[2], b[1]=-a[2], b[2]=a[0]+a[1];
        else if(a[1]+a[2]!=0) b[0]=a[2]+a[1], b[1]=-a[0], b[2]=-a[0];
        else b[0]=-a[1], b[1]=a[0]+a[2], b[2]=-a[1];
        for(int i=4; i<n; i+=2){
            b[i-1] = -a[i];
            b[i] = a[i-1];
        }
    }
    for(auto ele : b) cout << ele << " "; cout << endl;
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