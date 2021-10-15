// https://codeforces.com/contest/1593/problem/D2

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int max_val = 2e6 + 7;

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){ 
        cin>>arr[i]; 
        mp[arr[i]]+=1;
        arr[i] += max_val;
    }
    for(auto ele : mp){
        if(ele.second >= (n/2)){
            cout << -1 << endl;
            return;
        }
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    vector<int> rem(n), freq_rem(max_val);
    for(int i = max_val; i>0; i--){
        int mx = 0;
        for(int j=0; j<n; j++){
            rem[j] = arr[j]%i;
            freq_rem[rem[j]]+=1;
        }
        for(int j=0; j<n; j++){
            mx = max(mx, freq_rem[rem[j]]);
            freq_rem[rem[j]]--;
        }
        if(mx >= (n/2)){
            ans = i;
            break;
        }
    }
    cout << (ans==max_val?-1:ans) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}