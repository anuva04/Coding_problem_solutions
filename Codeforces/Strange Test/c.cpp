// https://codeforces.com/contest/1632/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int a, b; cin>>a>>b;
    int ans = b-a;
    for(int aa=a; aa<b; aa++){
        int bb = 0;
        for(int i=21; i>=0; i--){
            if((b>>i)&1) bb ^= (1<<i);
            else {
                if((aa>>i)&1) {
                    bb ^= (1<<i);
                    break;
                }
            }
        }
        ans = min(ans, (1-a-b) + aa + (aa | bb));
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}