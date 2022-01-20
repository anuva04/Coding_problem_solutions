// https://www.spoj.com/problems/MAIN74/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void multiply(long long F[2][2],long long M[2][2]);
void power(long long F[2][2],long long n);
long long fib(long long n);

long long fib(long long n)
{
    long long F[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(F,n-1);
    return F[0][0];
}

void multiply(long long F[2][2],long long M[2][2])
{

    long long x = ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod;
    long long y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
    long long z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod;
    long long w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;

}

void power(long long F[2][2], long long n)
{
    if( n == 0 || n == 1)
        return;
    long long M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if( n&1)
    multiply(F, M);
}

void solve(){
    ll n; cin>>n;
    if(n==0) cout << 0 << endl;
    else if(n==1) cout << 2 << endl;
    else cout << fib(n+3)%mod << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}