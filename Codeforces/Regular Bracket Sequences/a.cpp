// https://codeforces.com/contest/1574/problem/A
 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<string> res;
        string indi = "";
        for(int individual_brackets = 1; individual_brackets <= n; individual_brackets++){
            indi += "()";
            string ans = "";
            int rem = 2*n - 2*individual_brackets;
            for(int i=1; i<= (rem/2); i++){
                ans += "(";
            }
            ans += indi;
            for(int i=1; i<= (rem/2); i++){
                ans += ")";
            }
            res.push_back(ans);
        }
        for(int i=0; i<res.size(); i++){
            cout << res[i] << endl;
        }
    }
 
    return 0;
}