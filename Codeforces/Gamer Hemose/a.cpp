// https://codeforces.com/problemset/problem/1592/A

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
        int n, h; cin>>n>>h;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int last = a[n-1];
        int last_sec = a[n-2];
        if(h<=last) cout << 1 << endl;
        else {
            int cnt = (h/(last+last_sec))*2;
            int rem = h%(last+last_sec);
            if(rem==0) {
                cout << cnt << endl;
                continue;
            }
            if(rem<=last) cnt += 1;
            else cnt += 2;
            cout << cnt << endl;
        }
    }
    
    return 0;
}