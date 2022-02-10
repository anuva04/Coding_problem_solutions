// https://codeforces.com/problemset/problem/1625/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n,l; cin>>n>>l;
    vector<bitset<30>> words;
    for(int i=0; i<n; i++) {
        int x; cin>>x;
        words.push_back(bitset<30>(x));
        // cout << words[i] << endl;
    }
    bitset<30> res(0);
    for(int i=29; i>=0; i--){
        int cnt = 0;
        for(int j=0; j<n; j++) cnt += words[j][i];
        if(cnt*2 >= n) res[i] = 1;
        else res[i] = 0;
    }
    cout << res.to_ulong() << endl;
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