// https://codeforces.com/problemset/problem/1389/A

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        int x=2*l;
        if(x>r){
            cout << -1 << " " << -1 <<endl;
        }else{
            cout << l << " " << x <<endl;
        }
    }
    return 0;
}
