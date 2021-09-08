// https://codeforces.com/problemset/problem/1543/A

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
        ll a, b;
        cin>>a>>b;
        if(a==b) {cout << 0 << " " << 0 << endl; continue;}
        ll max_gcd = abs(a-b);
        ll lower_gap = a%max_gcd;
        ll upper_gap = max_gcd-lower_gap;
        ll steps = min(lower_gap, upper_gap);
        cout << max_gcd << " " << steps << endl;

    }
    return 0;
}