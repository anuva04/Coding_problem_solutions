// https://codeforces.com/problemset/problem/1527/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = n;
        ans = (int)log2(ans);
        ans = (int)pow(2,ans);
        cout << ans-1 << endl;
    }

    return 0;
}