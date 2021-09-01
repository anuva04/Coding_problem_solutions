// https://codeforces.com/problemset/problem/1546/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n, m; cin>>n>>m;
        vector<string> s(n+n-1);
        for(int i=0; i<2*n-1; i++) cin>>s[i];
        string res = "";
        for(int i=0; i<m; i++){
            char c = s[0][i];
            for(int j=1; j<2*n-1; j++){
                c ^= s[j][i];
            }
            res += c;
        }
        cout << res << endl;
    }
    return 0;
}