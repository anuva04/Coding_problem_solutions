// https://codeforces.com/problemset/problem/1551/B2

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    ll test; cin>>test;
    while(test--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        vector<int> ans(n);
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            if(mp[arr[i]].size()<k) mp[arr[i]].push_back(i);
        }
        int total_colored = 0;
        for(auto ele : mp){
            total_colored += ele.second.size();
        }
        int color = 0;
        total_colored -= total_colored%k;
        bool done = false;
        for(auto ele : mp){
            for(auto i : ele.second){
                ans[i] = ++color;
                color %= k;
                if(--total_colored == 0){
                    done = true;
                    break;
                }
            }
            if(done) break;
        }
        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}