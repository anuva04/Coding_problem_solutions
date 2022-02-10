// https://codeforces.com/problemset/problem/1385/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

int recurse(string& s, char ch, int i, int j){
    if(i == j){
        if(s[i] == ch) return 0;
        else return 1;
    }
    int mid_len = (j - i)/2;
    int i1 = i + mid_len;
    int j1 = i1 + 1;
    int ans1 = 0, ans2 = 0;
    for(int k=i; k<=i1; k++) if(s[k] != ch) ans1++;
    for(int k=j1; k<=j; k++) if(s[k] != ch) ans2++;
    ans1 += recurse(s, ch+1, j1, j);
    ans2 += recurse(s, ch+1, i, i1);
    return min(ans1, ans2);
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int ans = recurse(s, 'a', 0, n-1);
    cout << ans << endl;
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