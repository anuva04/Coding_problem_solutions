// https://codeforces.com/problemset/problem/1581/B

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
        int n,m,k;
        cin>>n>>m>>k;
        if(((n-1ll)*n>>1 < m) || (m < n-1)){
            cout << "NO" << endl;
            continue;
        }
        if(n==1){
            if(k>1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if(m < (n-1ll)*n>>1){
            if(k>3) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if(k>2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}