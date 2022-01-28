// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2470

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

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

void solve(){
    string s;
    while(cin>>s){
        int n = s.size();
        if(n==1) {
            cout << s << endl;
            continue;
        }

        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<int> pi = prefix_function(s1);
        // cout << s1 << endl;
        // for(auto ele : pi) cout << ele << ' '; cout << endl;
        int i=0, j=0;
        while(i<n){
            if(s[i] == s1[j]) i++, j++;
            else {if(j!=0) j = pi[j-1]; else i++;}
        }
        // cout << j << endl;
        for(int i=j; i<n; i++) s += s1[i];
        cout << s << endl;
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