// https://codeforces.com/contest/1638/problem/A

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
    int x;
    for(int i=0; i<n; i++) {
        cin>>x;
        a[i] = x;
        s[i] = x;
    }
    sort(s.begin(), s.end());
    int start = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == s[i]) start++;
        else break;
    }
    if(start != n){
        int mn = a[start];
        int idx = start;
        for(int i=start; i<n; i++){
            if(a[i] < mn){
                mn = a[i];
                idx = i;
            }
        }
        while(start < idx){
            swap(a[start++], a[idx--]);
        }
    }
    for(auto ele : a) cout << ele << ' '; cout << endl;
    
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