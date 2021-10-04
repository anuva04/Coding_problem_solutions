// https://codeforces.com/problemset/problem/1542/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;
    return (a.first > b.first);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        ll n; cin>>n;
        ll ans = 0, lcm = 1;
        ll i=2;
        while(true){
            ll a = n/lcm;
            lcm = lcm*i/__gcd(lcm,i);
            ll b = n/lcm;
            ans += (a-b)*i;
            ans %= mod;
            i+=1;
            if(lcm>n) break;
        }
        cout << ans << endl;
    }
    
    return 0;
}