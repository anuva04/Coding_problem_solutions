// https://codeforces.com/problemset/problem/1562/D1

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
        int n,q; cin>>n>>q;
        string s; cin>>s;
        int sign = 1;
        int charge[n];
        for(int i=0; i<n; i++){
            charge[i] = (s[i]=='+')?(1*sign):(-1*sign);
            sign *= -1;
        }
        int prefix_sum[n];
        prefix_sum[0] = charge[0];
        for(int i=1; i<n; i++){
            prefix_sum[i] = prefix_sum[i-1] + charge[i];
        }
        while(q--){
            int l,r; cin>>l>>r;
            int sum;
            if(l == 1) sum = prefix_sum[r-1];
            else sum = prefix_sum[r-1]-prefix_sum[l-2];
            if(sum == 0) cout << 0 << endl;
            else if ((r-l+1)%2 == 0) cout << 2 << endl;
            else cout << 1 << endl;
        }
    }
    return 0;
}