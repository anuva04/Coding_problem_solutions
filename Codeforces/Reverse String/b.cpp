// https://codeforces.com/problemset/problem/1553/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool solve(string s, string t){
    int s_len = s.length();
    int t_len = t.length();
    for(int idx = 0; idx<s_len; idx++){
        for(int right = 0; right<s_len; right++){
            int left = t_len - 1 - right;
            string res = "";
            res += s[idx];
            int r = right;
            int l = left;
            int i = idx+1;
            while(r--){
                if(i<s_len){ res+=s[i]; i+=1;}
                else break;
            }
            i-=2;
            while(l--){
                if(i>=0) { res+=s[i]; i-=1;}
                else break;
            }
            // cout << "res= " << res << endl;
            if(res.size() != t.size()) continue;
            bool flag = true;
            for(int j=0; j<res.size(); j++){
                if(res[j]!=t[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        string s, t; cin>>s>>t;
        bool ans = solve(s,t);
        if(ans) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}