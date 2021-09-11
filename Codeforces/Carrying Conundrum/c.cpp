// https://codeforces.com/problemset/problem/1567/C

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
        string s1, s2;
        for(int i=0; i<s.size(); i++){
            if(i%2 == 0) s1 += s[i];
            else s2 += s[i];
        }
        if(s2.size() == 0) cout << stoi(s1) - 1 << endl;
        else cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
    }

    return 0;
}