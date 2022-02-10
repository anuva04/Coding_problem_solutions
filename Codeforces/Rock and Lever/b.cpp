// https://codeforces.com/problemset/problem/1420/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n; cin>>n;
    unordered_map<int,int> bit_cnt;
    int num;
    for(int i=0; i<n; i++) {
        cin>>num;
        int bit = log2(num) + 1;
        bit_cnt[bit]++;
    }
    ll cnt = 0;
    for(auto ele : bit_cnt){
        cnt += (1LL*ele.second*(ele.second-1))/2;
    }
    cout << cnt << endl;
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