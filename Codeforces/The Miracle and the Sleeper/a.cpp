// https://codeforces.com/problemset/problem/1562/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int l,r; cin>>l>>r;
        int ans;
        int div = (r/2)+1;
        if(div<l) ans = r-l;
        else ans = r-div;
        cout << ans << endl;
    }
    return 0;
}