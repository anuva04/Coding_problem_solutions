// https://codeforces.com/problemset/problem/126/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    int m = s.size();
    vector<int> prefix_suffix(m+1);
    prefix_suffix[0] = -1;
    for (int i = 0; i < m; ++i){
        prefix_suffix[i+1] = prefix_suffix[i];
        while(prefix_suffix[i+1] > -1 && s[prefix_suffix[i+1]] != s[i]){
            prefix_suffix[i+1] = prefix_suffix[prefix_suffix[i+1]];
        }
        prefix_suffix[i+1]++;
    }
    // for(auto ele : prefix_suffix) cout << ele << ' '; cout << endl;
    int longest_ps = prefix_suffix[m];
    if(longest_ps == 0) {
        cout << "Just a legend" << endl;
        return;
    }
    for(int i=1; i<m; i++){
        if(prefix_suffix[i] == longest_ps) {
            cout << s.substr(0, prefix_suffix[i]) << endl;
            return;
        }
    }
    int longest_ps_sub = prefix_suffix[prefix_suffix[m]];
    if(longest_ps_sub == 0) {
        cout << "Just a legend" << endl;
        return;
    }
    cout << s.substr(0, longest_ps_sub) << endl;
    return;
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