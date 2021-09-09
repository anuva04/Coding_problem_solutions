// https://codeforces.com/problemset/problem/1539/A

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
        ll n,x,t;
        cin>>n>>x>>t;
        ll diss_per_person = t/x;
        if(diss_per_person>(n-1)){
            ll ans = ((n)*(n-1))/2;
            cout << ans << endl;
        } else {
            ll ideal_diss = diss_per_person*n;
            ll excess = 0;
            if(diss_per_person>0){
                excess = ((diss_per_person)*(diss_per_person+1))/2;
            }
            cout << ideal_diss - excess << endl;
        }
    }

    return 0;
}