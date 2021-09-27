// https://codeforces.com/problemset/problem/1566/C

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
        string s1, s2;
        cin>>s1>>s2;
        int ans = 0;
        int i=0;
        while(i<n){
            if(s1[i] != s2[i]){
                ans += 2;
                i+=1;
            } else if (s1[i] == '0'){
                if(i<n-1){
                    if(s1[i+1]!=s2[i+1]){
                        ans += 1;
                        i += 1;
                    } else if(s1[i+1] == '0'){ans += 1; i+=1;}
                    else {
                        ans += 2;
                        i += 2;
                    }
                } else {
                    ans += 1;
                    i += 1;
                }
            } else {
                if(i<n-1){
                    if(s1[i+1]!=s2[i+1]){
                        i += 1;
                    } else if (s1[i+1] == '1') i+=1;
                    else {
                        ans += 2; i+=2;
                    }
                } else {
                    i += 1;
                }
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}