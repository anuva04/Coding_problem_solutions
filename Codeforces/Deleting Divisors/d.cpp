// https://codeforces.com/problemset/problem/1537/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n&1) cout << "Bob" << endl;
        else {
            if(!(n&(n-1))){
                int cnt = 0;
                while(n>0){
                    n/=2;
                    cnt+=1;
                }
                if(cnt&1) cout << "Alice" << endl;
                else cout << "Bob" << endl;
            } else cout << "Alice" << endl;
        }
    }
}