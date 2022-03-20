// http://codeforces.com/problemset/problem/295/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {cin>>adj[i][j]; d[i][j] = adj[i][j];}
    }
    vector<int> rem(n);
    for(int i=0; i<n; i++) cin>>rem[i];

    vector<ll> answers;
    
    for(int i1=n-1; i1>=0; --i1){
        int k = rem[i1]-1;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) {
                if(d[i][k] < INF && d[k][j] < INF) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
        ll ans = 0;
        for(int i=i1; i<n; i++){
            for(int j=i1; j<n; j++) ans += d[rem[i]-1][rem[j]-1];
        }
        answers.push_back(ans);
    }
    for(int i=n-1; i>=0; i--) cout << answers[i] << ' '; cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}