// https://www.spoj.com/problems/SKYLINE/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

const ll MOD = 1000000;
const ll MAX = 1002;

ll catalan[MAX];
void init() {
    catalan[0] = catalan[1] = 1;
    for (ll i=2; i<MAX; i++) {
        catalan[i] = 0;
        for (ll j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
}


void solve(int n){
    cout << catalan[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    init();

    while(true){
        int n; cin>>n;
        if(n==0) break;
        solve(n);
    }
    
    // int test; cin>>test;
    // while(test--){
    //     solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}