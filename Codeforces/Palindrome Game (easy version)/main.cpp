// https://codeforces.com/problemset/problem/1527/B1

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int cntz=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') cntz+=1;
        }
        if(cntz==0){
            cout << "DRAW" << endl;
            continue;
        }
        if(cntz==1){
            cout << "BOB" << endl;
            continue;
        }
        if(n&1){
            if(s[n/2]=='0') cout << "ALICE" << endl;
            else cout << "BOB" << endl;
        } else cout << "BOB" << endl;
    }

    return 0;
}