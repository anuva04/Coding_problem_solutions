// https://codeforces.com/contest/1526/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int x; cin>>x;
        int b = x%11;
        int a = x - 111*b;
        if(a>=0 && a%11==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}