// https://codeforces.com/problemset/problem/1521/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        ll a, b; cin>>a>>b;
        if(b==1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            ll x = a, y = a*b, z = a*(b+1);
            cout << x << " " << y << " " << z << endl;
        }
    }

    return 0;
}