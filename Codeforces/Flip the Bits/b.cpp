// https://codeforces.com/contest/1504/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    string a, b; cin>>a>>b;
    vector<int> diff(n);
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == '0') cnt += 1;
        else cnt -= 1;
        diff[i] = cnt;
    }
    int num_flips = 0;
    for(int i=n-1; i>=0; i--){
        if(num_flips&1){
            if(a[i] != b[i]) continue;
            if(diff[i] == 0) num_flips+=1;
            else {
                cout << "NO" << endl;
                return;
            }
        } else {
            if(a[i] == b[i]) continue;
            if(diff[i] == 0) num_flips += 1;
            else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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