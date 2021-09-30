// https://codeforces.com/problemset/problem/1499/B

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
        string res = "";
        bool prev_removed = false;
        int first_11 = -1;
        int last_00 = -1;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='1' && s[i-1]=='1'){
                first_11 = i;
                break;
            }
        }
        if(first_11 == -1){
            cout << "YES" << endl;
            continue;
        }
        for(int i=s.size()-2; i>=0; i--){
            if(s[i]=='0' && s[i+1]=='0'){
                last_00 = i;
                break;
            }
        }
        if(last_00 == -1){
            cout << "YES" << endl;
            continue;
        }
        if(first_11>last_00) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}