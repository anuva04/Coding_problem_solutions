// https://codeforces.com/contest/1612/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, a, b; cin>>n>>a>>b;
    vector<int> ans(n+1, -1);
    ans[1] = a;
    ans[n] = b;
    int num = n;
    int i = 2;
    while(i<=n-1){
        if(num != a && num!=b){
            ans[i++] = num;
        }
        num--;
    }
    // for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
    for(int i=2; i<=n/2; i++){
        if(ans[i]<ans[1]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i=n/2+1; i<=n-1; i++){
        if(ans[i]>ans[n]){
            cout << -1 << endl;
            return;
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << ' '; cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}