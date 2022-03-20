// https://www.spoj.com/problems/CHICAGO/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    double adj[101][101];
    int n, e;
    while(cin>>n && n){
        cin>>e;
        double weight;
        int u, v;
        memset(adj, 0, sizeof adj);
        while(e--){
            cin>>u>>v>>weight;
            adj[u][v] = adj[v][u] = weight/100.0;
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    adj[i][j] = max(adj[i][j], adj[i][k]*adj[k][j]);
                }
            }
        }
        cout << fixed << setprecision(6) << adj[1][n]*100 << " percent" << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}