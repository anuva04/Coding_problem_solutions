// https://codeforces.com/problemset/problem/1494/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

bool check(int n, int u, int r, int d, int l){
    if(u>n-2 || u<0 || r>n-2 || r<0 || d>n-2 || d<0 || l>n-2 || l<0) return false;
    return true;
}

void solve(){
    int n; cin>>n;
    int u,r,d,l; cin>>u>>r>>d>>l;

    bool ans = false;
    ans |= check(n, u, r, d, l); // 0000
    ans |= check(n, u, r, d-1, l-1); // 0001
    ans |= check(n, u, r-1, d-1, l); // 0010
    ans |= check(n, u, r-1, d-2, l-1); // 0011
    ans |= check(n, u-1, r-1, d, l); // 0100
    ans |= check(n, u-1, r-1, d-1, l-1); // 0101
    ans |= check(n, u-1, r-2, d-1, l); // 0110
    ans |= check(n, u-1, r-2, d-2, l-1); // 0111
    ans |= check(n, u-1, r, d, l-1); // 1000
    ans |= check(n, u-1, r, d-1, l-2); // 1001
    ans |= check(n, u-1, r-1, d-1, l-1); // 1010
    ans |= check(n, u-1, r-1, d-2, l-2); // 1011
    ans |= check(n, u-2, r-1, d, l-1); // 1100
    ans |= check(n, u-2, r-1, d-1, l-2); // 1101
    ans |= check(n, u-2, r-2, d-1, l-1); // 1110
    ans |= check(n, u-2, r-2, d-2, l-2); // 1111
    
    cout << ((ans) ? "yes" : "no") << endl;
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