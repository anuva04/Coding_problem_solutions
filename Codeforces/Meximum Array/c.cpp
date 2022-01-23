// https://codeforces.com/contest/1629/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<int> arr(n+1);
    vector<set<int>> num_indices(n+1);
    for(int i=1; i<=n; i++) {
        cin>>arr[i];
        num_indices[arr[i]].insert(i);
    }
    vector<int> ans;
    int curr_mex = n;
    int border = 0;
    while(true){
        for(int i=0; i<n; i++){
            if((int)num_indices[i].size() == 0){
                curr_mex = i;
                break;
            }
        }
        if(curr_mex == 0) break;
        ans.push_back(curr_mex);
        int curr_border = INT_MIN;
        for(int i=0; i<curr_mex; i++){
            curr_border = max(curr_border, *(num_indices[i].begin()));
        }
        border = max(border, curr_border);
        for(int i=0; i<curr_mex; i++){
            while((int)num_indices[i].size()>0 && *(num_indices[i].begin()) <= curr_border)
                num_indices[i].erase(num_indices[i].begin());
        }
    }
    border += 1;
    while(border <= n) {ans.push_back(0); border++;}
    cout << ans.size() << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}