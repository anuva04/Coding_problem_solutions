// https://codeforces.com/contest/1638/problem/B

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
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int odd = -1, even = -1;
    for(int i=0; i<n; i++){
        if(a[i]%2 == 0){
            if(even > a[i]){
                cout << "no" << endl;
                return;
            } else {
                even = a[i];
            }
        } else {
            if(odd > a[i]){
                cout << "no" << endl;
                return;
            } else odd = a[i];
        }
    }
    cout << "yes" << endl;
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