// https://codeforces.com/problemset/problem/1556/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int solve(int parity, vector<int> arr, int n){
    int ans = 0;
    int delta = 0;
    for(int i=0; i<n; i++){
        if((arr[i]%2) != parity){
            delta += (parity - (arr[i]%2));
        }
        ans += abs(delta);
        parity ^= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> arr(n);
        int odd_cnt = 0, even_cnt = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if((arr[i]&1) == 0) even_cnt += 1;
            else odd_cnt += 1;
        }
        if(n%2 == 0){
            if(even_cnt == odd_cnt){
                int ans1 = solve(0, arr, n);
                int ans2 = solve(1, arr, n);
                cout << min(ans1, ans2) << endl;
            }
            else cout << -1 << endl;
        } else {
            if(even_cnt == odd_cnt+1) cout << solve(0, arr, n) << endl;
            else if (odd_cnt == even_cnt+1) cout << solve(1, arr, n) << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}