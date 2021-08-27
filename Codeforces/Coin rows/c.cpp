// https://codeforces.com/problemset/problem/1555/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int m; cin>>m;
        vector<vector<int>> v(2, vector<int>(m));
        for(int i=0; i<2; i++){
            for(int j=0; j<m; j++) cin>>v[i][j];
        }
        int top_sum = 0, bot_sum = 0;
        for(int i=1; i<m; i++) top_sum += v[0][i];
        int ans = max(top_sum, bot_sum);
        for(int i=1; i<m; i++){
            top_sum -= v[0][i];
            bot_sum += v[1][i-1];
            ans = min(ans, max(top_sum, bot_sum));
        }
        cout << ans << endl;
    }
    return 0;
}