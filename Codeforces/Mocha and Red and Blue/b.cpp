// https://codeforces.com/problemset/problem/1559/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        int i;
        for(i=0; i<n; i++){
            if(s[i] != '?'){
                break;
            }
        }
        // cout << i << endl;
        for(int j=i-1; j>=0; j--){
            if(s[j] != '?') continue;
            if(j<=n-2){
                if(s[j+1]=='R') s[j] = 'B';
                else s[j] = 'R';
            } else s[j] = 'R';
        }
        for(int j=i+1; j<n; j++){
            if(s[j] != '?') continue;
            if(s[j-1]=='R') s[j]='B';
            else s[j]='R';
        }
        cout << s << endl;
    }
    return 0;
}