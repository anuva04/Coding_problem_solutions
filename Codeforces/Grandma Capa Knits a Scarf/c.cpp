// https://codeforces.com/contest/1582/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int go(string s, int l, int r, char c){
    int cnt = 0;
    while(l<=r){
        if(s[l]==s[r]) l++, r--;
        else if(s[l] == c) cnt += 1, l+=1;
        else if(s[r] == c) cnt += 1, r-=1;
        else return -1;
    }
    return cnt;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int l = 0, r = n-1;
    while(l<=r){
        if(s[l] == s[r]) l++, r--;
        else break;
    }
    if(l>=r){
        cout << 0 << endl;
        return;
    }
    int ans1 = go(s, l, r, s[l]);
    int ans2 = go(s, l, r, s[r]);
    if(ans1==-1 && ans2==-1) cout << -1 << endl;
    else if(ans1==-1) cout << ans2 << endl;
    else if(ans2 == -1) cout << ans1 << endl;
    else cout << min(ans1, ans2) << endl;
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}