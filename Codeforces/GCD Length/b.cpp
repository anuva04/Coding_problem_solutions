// https://codeforces.com/problemset/problem/1511/B

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
        int a,b,c; cin>>a>>b>>c;
        string x = "1";
        a-=1;
        while(a--){
            x += "0";
        }
        string y = "1";
        int aa = b-c;
        while(aa--){
            y += "1";
        }
        c-=1;
        while(c--) y+= "0";
        cout << x << " " << y << endl;
    }

    return 0;
}