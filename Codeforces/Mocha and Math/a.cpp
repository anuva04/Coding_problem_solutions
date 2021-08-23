// https://codeforces.com/problemset/problem/1559/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        int ans; cin>>ans;
        for(int i=2; i<=n; i++){
            int x; cin>>x;
            ans &= x;
        }
        cout << ans << endl;
    }
    return 0;
}