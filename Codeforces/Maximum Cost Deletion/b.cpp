// https://codeforces.com/problemset/problem/1550/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n, a, b; cin>>n>>a>>b;
        string s; cin>>s;
        int ans = 0;
        if(b>=0){
            ans = n*(a+b);
        }else {
            int i=0;
            int cnt=0, total_cnt=0;
            while(i<n){
                while(i<n && s[i]==s[0]){
                    i++;
                    cnt = 0;
                }
                while(i<n && s[i]!=s[0]){
                    i++;
                    cnt += 1;
                    total_cnt += 1;
                }
                if(cnt > 0){
                    ans += (a*cnt + b);
                }
                // cout << cnt << " " << ans << endl;
            }
            ans += (n-total_cnt)*a + b;
        }
        cout << ans << endl;
    }
    return 0;
}