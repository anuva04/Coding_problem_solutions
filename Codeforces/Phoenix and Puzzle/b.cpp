// https://codeforces.com/problemset/problem/1515/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool isSq(int x){
    int y = sqrt(x);
    if(y*y == x) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        if(n%2==0 && isSq(n/2)) cout << "YES" << endl;
        else if(n%4==0 && isSq(n/4)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}