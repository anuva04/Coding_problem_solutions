// 

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
    string s; cin>>s;
    int n = s.size();
    vector<int> pi = prefix_function(s);

    vector<pair<int,int>> len_cnt;
    len_cnt.push_back({n, 1});

    // Counting the number of occurrences of each prefix
    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;

    int j = n-1;
    while(j>0){
        int len = pi[j];
        if(len>0){
            len_cnt.push_back({len, ans[len]});
        }
        j = len-1;
    }
    sort(len_cnt.begin(), len_cnt.end());

    cout << (int)len_cnt.size() << endl;
    for(auto ele : len_cnt) cout << ele.first << ' ' << ele.second << endl;
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