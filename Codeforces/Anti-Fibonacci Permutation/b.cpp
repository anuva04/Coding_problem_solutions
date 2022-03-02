// https://codeforces.com/contest/1644/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXN 305
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

void solve(){
    int n; cin>>n;

    if(n==3){
        int ans[3][3] = {{3,2,1},{1,3,2},{3,1,2}};
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++){
                cout << ans[i][j] << ' ';
            } cout << endl;
        }
        return;
    }
    vector<int> ref;
    for(int i=1; i<=n; i++) ref.push_back(i);

    for(int i=0; i<n; i++){
        vector<int> ans = ref;
        swap(ans[0], ans[i]);
        if(i+2<n) swap(ans[i+1], ans[i+2]);
        for(auto ele : ans) cout << ele << ' '; cout << endl;
    }
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}