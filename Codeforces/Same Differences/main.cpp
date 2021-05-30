// https://codeforces.com/problemset/problem/1520/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin>>t;
    while(t--){
        ll ans = 0;
        int n; cin>>n;
        map<int,int> mp;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            x -= i;
            ans += mp[x];
            mp[x] += 1;
        }
        cout << ans << endl;
    }

    return 0;
}