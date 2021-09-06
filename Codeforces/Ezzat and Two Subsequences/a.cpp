// https://codeforces.com/problemset/problem/1557/A

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
        int n; cin>>n;
        int arr[n];
        int mx = INT_MIN;
        ll sum = 0;
        for(int i=0; i<n; i++){ 
            cin>>arr[i];
            mx = max(mx, arr[i]);
            sum += arr[i];
        }
        sum -= mx;
        ld ans = mx + ld((ld)sum/(ld)(n-1));
        cout << fixed << setprecision(9);
        cout << ans << endl;    
    }
    return 0;
}