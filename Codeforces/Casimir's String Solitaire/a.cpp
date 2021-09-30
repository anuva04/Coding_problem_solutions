// https://codeforces.com/problemset/problem/1579/A

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
        string s; cin>>s;
        int a=0, b=0, c=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'A') a+=1;
            else if (s[i] == 'B') b+=1;
            else c+=1;
        }
        if(a+c == b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}