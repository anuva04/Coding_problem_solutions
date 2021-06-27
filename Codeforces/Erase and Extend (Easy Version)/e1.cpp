// https://codeforces.com/problemset/problem/1537/E1
#include <bits/stdc++.h>
using namespace std;
#define int long long

string solve(string s, int k){
    int n = s.size();
    string ans = "";
    for(int i=0; i<k; i++) ans += (char)(s[i%n]);
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vector<string> pre;
    for(int i=0; i<n; i++) pre.push_back(s.substr(0,i+1));
    vector<string> possibles;
    for(auto str : pre){
        string res = solve(str, k);
        possibles.push_back(res);
    }
    sort(possibles.begin(), possibles.end());
    cout << possibles[0] << endl;
    return 0;
}