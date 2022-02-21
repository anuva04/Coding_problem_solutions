// https://codeforces.com/contest/1635/problem/C

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
    vector<int> a(n), s(n);
    for(int i=0; i<n; i++) cin>>a[i], s[i] = a[i];
    sort(s.begin(), s.end());
    if(a[n-2]>a[n-1]){
        cout << -1 << endl;
        return;
    }
    if(a[n-1] < 0){
        for(int i=0; i<n; i++){
            if(a[i] != s[i]) {
                cout << -1 << endl;
                return;
            }
        }
        cout << 0 << endl;
        return;
    }
    cout << n-2 << endl;
    for(int i=1; i<=n-2; i++) cout << i << ' ' << n-1 << ' ' << n << endl;
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