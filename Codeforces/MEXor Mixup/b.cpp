// https://codeforces.com/problemset/problem/1567/B

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
        ll a,b;
        cin>>a>>b;
        ll xor_till_now;
        if(a % 4 == 1) xor_till_now = a-1;
        else if(a % 4 == 2) xor_till_now = 1;
        else if(a % 4 == 3) xor_till_now = a;
        else xor_till_now = 0;
        if(xor_till_now == b){
            cout << a << endl;
        } else if((xor_till_now^b) != a) cout << a+1 << endl;
        else cout << a+2 << endl;
    }

    return 0;
}