// https://codeforces.com/problemset/problem/1553/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int solve(string& s, int idx, int w1, int r1, int w2, int r2){
    // cout << s << " idx= " << idx << " w1= " << w1 << " r1= " << r1 << " w2= " << w2 << " r2= " << r2 << endl;
    if(idx == 10) return idx;
    if((w1 > w2+r2) || (w2 > w1+r1)) return idx;
    if(idx%2==0){
        if(s[idx]=='1') return solve(s, idx+1, w1+1, r1-1, w2, r2);
        else if(s[idx]=='0') return solve(s, idx+1, w1, r1-1, w2, r2);
        else return min(solve(s, idx+1, w1+1, r1-1, w2, r2), solve(s, idx+1, w1, r1-1, w2, r2));
    } else {
        if(s[idx]=='1') return solve(s, idx+1, w1, r1, w2+1, r2-1);
        else if(s[idx]=='0') return solve(s, idx+1, w1, r1, w2, r2-1);
        else return min(solve(s, idx+1, w1, r1, w2+1, r2-1), solve(s, idx+1, w1, r1, w2, r2-1));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--){
        string s; cin>>s;
        cout << solve(s, 0, 0, 5, 0, 5) << endl;
    }
    return 0;
}