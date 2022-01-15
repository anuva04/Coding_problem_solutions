// https://codeforces.com/contest/1612/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool solve1(ll a, ll b, ll x){
    if(x>max(a, b)) return false;
    if(a==0 || b==0) return false;
    if(x==a || x==b) return true;
    if(a<b) swap(a, b);
    if((a-x)%b == 0) return true;
    return solve1(b, a%b, x);
}

void solve(){
    ll a, b, x;
    cin>>a>>b>>x;
    if(solve1(a, b, x)) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}