// https://www.spoj.com/problems/FUNPROB/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;


void solve(){
    while(true){
        ld n, m; cin>>n>>m;
        if(n==0 && m==0) return;
        ld ans = 0.0;
        if(n <= m){
            ans = (ld)((ld)(m+1-n)/(m+1));
        }
        cout << fixed << setprecision(6) << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}