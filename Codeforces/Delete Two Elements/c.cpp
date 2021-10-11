// https://codeforces.com/contest/1598/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    map<int,int> mp;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int x; cin>>x;
        mp[x]++;
        arr[i] = x;
    }
    ll ans = 0;
    ll sum = accumulate(arr.begin(), arr.end(), 0LL);
    if((2*sum)%n != 0){
        cout << 0 << endl;
        return;
    }
    ll to_remove = (2*sum)/n;
    for(int i=0; i<n; i++){
        int y = to_remove-arr[i];
        if(mp.count(y)) ans += mp[y];
        if(arr[i]==y) ans -= 1;
    }
    cout << ans/2 << endl;
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