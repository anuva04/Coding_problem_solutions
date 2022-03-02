// https://www.spoj.com/problems/ADATEAMS/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 1;

int factorial[MAXN], inverse_factorial[MAXN];

int pow(int a, int p){
    if(p==0) return 1;
    int ans = 1LL*pow(a, p>>1)%mod;
    ans = 1LL*ans*ans%mod;
    if(p&1) ans = 1LL*ans*a%mod;
    return ans;
}

int nck(int n, int k){
    return 1LL*factorial[n]*inverse_factorial[k]%mod * inverse_factorial[n-k]%mod;
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    factorial[0] = inverse_factorial[0] = 1;
    for(int i=1; i<MAXN; i++){
        factorial[i] = 1LL*factorial[i-1]*i%mod;
        inverse_factorial[i] = pow(factorial[i], mod-2);
    }

    int n, a, b, d;

    while(cin>>n>>a>>b>>d){
        cout << 1LL*nck(n,a)*pow(nck(b,d), a)%mod << endl;
    }

    // ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}