// https://codeforces.com/problemset/problem/1555/B

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
        int W, H; cin>>W>>H; // 8, 5
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2; // 2 1 7 4
        int w, h; cin>>w>>h;
        int ans = INF;

        if(w <= W - (x2-x1)){
            ans = min(ans, max(0, w-x1));
            ans = min(ans, max(0, w-(W-x2)));
        }
        if(h <= H - (y2-y1)){
            ans = min(ans, max(0, h-y1));
            ans = min(ans, max(0, h-(H-y2)));
        }
        cout << fixed << setprecision(9);
        if(ans == INF) cout << -1 << endl;
        else cout << double(ans) << endl;
    }
    return 0;
}