// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1963

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int maxn = 81;
string s, b;
int dp[maxn][maxn];

vector<int> prefix_function(string& s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int findPeriodicLen(vector<int>& pi, int sz){
    int k = sz - pi[sz-1];
    if(sz%k) return sz;
    return k;
}

int getMaximalFactoring(int, int);

int findIrreducibleLength(int i, int j){
    b = s.substr(i, j-i+1);
    int sz = j-i+1;
    vector<int> pi = prefix_function(b);

    int periodic_len = findPeriodicLen(pi, sz);
    cout << i << ' ' << j << ' ' << periodic_len << endl;
    if(periodic_len == sz) return periodic_len;
    return getMaximalFactoring(i, i+periodic_len-1);
}

int getMaximalFactoring(int i, int j){
    if(i==j) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = findIrreducibleLength(i, j);
    for(int k=i; k<j; k++) ans = min(ans, getMaximalFactoring(i, k) + getMaximalFactoring(k+1, j));
    return dp[i][j] = ans;
}

void solve(){
    while(true){
        cin>>s;
        if(s == "*") return;
        memset(dp, -1, sizeof dp);
        cout << getMaximalFactoring(0, s.size()-1) << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}