// https://codeforces.com/problemset/problem/1523/B

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
        for(int i=0; i<n; i++) cin>>arr[i];
        cout << 6*(n/2) << endl;
        for(int i=1; i<=n-1; i+=2){
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 1 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 2 << " " << i << " " << i+1 << endl;
            cout << 1 << " " << i << " " << i+1 << endl;
        }
    }
    return 0;
}