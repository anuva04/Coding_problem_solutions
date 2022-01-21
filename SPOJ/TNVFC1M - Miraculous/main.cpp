// https://www.spoj.com/problems/TNVFC1M/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> log_table;
vector<vector<int>> min_st;
vector<int> a;
int n;

void build(int n, int k){
    min_st = vector<vector<int>>(n, vector<int>(k+1));

    for(int i=0; i<n; i++) {
        min_st[i][0] = i;
    }
    
    for(int j=1; j<=k; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            if(a[min_st[i][j-1]] < a[min_st[i+(1<<(j-1))][j-1]])
                min_st[i][j] = min_st[i][j-1];
            else
                min_st[i][j] = min_st[i+(1<<(j-1))][j-1];
        }
    }
}

int getMin(int l, int r){
    if(l>=n || r<0) return -1;
    int j = log_table[r-l+1];
    if(a[min_st[l][j]] < a[min_st[r-(1<<j)+1][j]]) return min_st[l][j];
    else return min_st[r-(1<<j)+1][j];
}

void solve(){
    int h, b, e;
    while(cin>>n>>h>>b>>e){
        a.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];

        int k = 20;
        build(n, k);

        vector<int> ans(n,0);

        for(int i=0; i<n; i++){
            int j = max(0, i-h+1);
            int min_idx = getMin(j, i);
            ans[min_idx]++;
        }

        b -= 1, e -= 1;
        for(int i=b; i<=e; i++) cout << ans[i] << ' ';
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n1 = 10005;
    log_table.resize(n1+1);
    log_table[1] = 0;
    for(int i=2; i<=n1; i++) log_table[i] = log_table[i/2]+1;

    
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