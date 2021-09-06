// https://codeforces.com/problemset/problem/1562/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        int mid = n/2;
        int found = false;
        for(int i=0; i<mid; i++){
            if(s[i] == '0'){
                cout << i+2 << " " << n << " " << i+1 << " " << n << endl;
                found = true;
                break;
            }
        }
        if(found) continue;
        for(int i=mid; i<n; i++){
            if(s[i] == '0'){
                cout << 1 << " " << i+1 << " " << 1 << " " << i << endl;
                found = true;
                break;
            }
        }
        if(found) continue;
        cout << 1 << " " << n-1 << " " << 2 << " " << n << endl;
    }
    return 0;
}