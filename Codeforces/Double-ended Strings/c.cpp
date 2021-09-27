// https://codeforces.com/problemset/problem/1506/C

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
        string a, b; cin>>a>>b;
        int a_len = a.size();
        int b_len = b.size();
        int dp[2][b_len];
        memset(dp, 0, sizeof dp);
        int res = 0;
        for(int i=1; i<=a_len; i++){
            for(int j=1; j<=b_len; j++){
                if(a[i-1] == b[j-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1] + 1;
                    res = max(res, dp[i%2][j]);
                } else dp[i%2][j] = 0;
            }
        }
        cout << (a_len-res+b_len-res) << endl;
    }
    
    return 0;
}