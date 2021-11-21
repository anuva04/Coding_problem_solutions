// https://codeforces.com/contest/1602/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    vector<int> cnt_set_bits(32, 0);
    for(int i=0; i<=31; i++){
        for(int j=0; j<n; j++){
            if(a[j]&(1<<i)) cnt_set_bits[i]++;
        }
    }
    vector<int> ans;
    for(int k=1; k<=n; k++){
        bool flag = true;
        for(int j=0; j<=31; j++){
            if(cnt_set_bits[j]%k != 0) {
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(k);
    }
    for(auto ele : ans) cout << ele << ' '; cout << endl;
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