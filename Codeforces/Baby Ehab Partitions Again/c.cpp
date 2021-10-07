// https://codeforces.com/contest/1516/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bitset<200005> bit;
void build(vector<int>& arr){
    bit.reset();
    int n = arr.size();
    bit[0] = 1;
    for(int i=0; i<n; i++){
        bit |= (bit << arr[i]);
    }
}

bool query(int sum){
    return bit[sum];
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    const int sum = accumulate(arr.begin(), arr.end(), 0);
    if(sum%2){
        cout << 0 << endl;
        return;
    }
    build(arr);
    if(!query(sum/2)){
        cout << 0 << endl;
        return;
    }
    pair<int,int> min_tz_idx(20, 0);
    for(int i=0; i<n; i++){
        min_tz_idx = min(min_tz_idx, {__builtin_ctz(arr[i]), i+1});
    }
    cout << 1 << endl;
    cout << min_tz_idx.second << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    solve();
    
    return 0;
}