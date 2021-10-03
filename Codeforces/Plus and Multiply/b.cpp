// https://codeforces.com/problemset/problem/1542/B

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
        ll n,a,b;
        cin>>n>>a>>b;
        if(a==1){
            if((n-1)%b == 0) cout << "yes" << endl;
            else cout << "NO" << endl;
            continue;
        }
        ll a1 = 1;
        bool found = false;
        while(a1<=n){
            if((n-a1)%b == 0){
                cout << "YES" << endl;
                found = true;
                break;
            }
            a1 *= a;
        }
        if(!found) cout << "NO" << endl;
    }
    
    return 0;
}