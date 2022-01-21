// https://www.spoj.com/problems/RMQSQ/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int log[n+1];
    log[1] = 0;
    for(int i=2; i<=n; i++) log[i] = log[i/2]+1;
    int k = 25;
    int sparse_table[n][k+1];
    for(int i=0; i<n; i++) sparse_table[i][0] = arr[i];
    for(int j=1; j<=k; j++){
        for(int i=0; i+(1<<j)<=n; i++)
            sparse_table[i][j] = min(sparse_table[i][j-1], sparse_table[i+(1<<(j-1))][j-1]);
    }

    int q; cin>>q;
    int l, r; 
    while(q--){
        cin>>l>>r;
        int j = log[r-l+1];
        int minimum = min(sparse_table[l][j], sparse_table[r-(1<<j)+1][j]);
        cout << minimum << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}