// https://codeforces.com/problemset/problem/1566/D1

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
        int n, m; cin>>n>>m;
        int arr[m];
        for(int i=0; i<m; i++) cin>>arr[i];
        ll ans = 0;
        for(int i=1; i<m; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]) ans+=1;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}