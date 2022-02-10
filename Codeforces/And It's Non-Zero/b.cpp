// https://codeforces.com/problemset/problem/1615/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

const int maxn = 200005;
int pre[maxn][27];

void solve(){
    int l, r; cin>>l>>r;
    int ans = 0;
    for(int i=0; i<27; i++){
        int ones = pre[r][i] - pre[l-1][i];
        ans = max(ans, ones);
    }
    cout << (r-l+1) - ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    memset(pre, 0, sizeof pre);
    for(int i=1; i<maxn; i++){
        for(int j=0; j<27; j++){
            pre[i][j] += (((i>>j)&1) + pre[i-1][j]);
        }
    }

    // for(int i=0; i<11; i++){
    //     for(int j=26; j>=0; j--) cout << pre[i][j] << ' ';
    //     cout << endl;
    // }

    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}