// https://codeforces.com/contest/1593/problem/D1

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);


void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int g = abs(a[0]-a[1]);
    for(int i=1; i<n; i++){
        int diff = abs(a[0] - a[i]);
        // cout << diff << " ";
        g = __gcd(g, diff);
    }
    if(g==0) cout << -1 << endl;
    else cout << g << endl;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}