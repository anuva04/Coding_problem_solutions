// https://codeforces.com/problemset/problem/1521/B

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
        int min_idx=-1, min_num = INT_MAX;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            if(x<min_num){
                min_num = x;
                min_idx = i;
            }
        }
        min_idx += 1;
        cout << n-1 << endl;
        for(int i=1; i<=n; i++){
            if(i == min_idx) continue;
            cout << min_idx << " " << i << " " << min_num << " " << min_num + abs(min_idx-i) << endl;
        }
    }

    return 0;
}