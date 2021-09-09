// https://codeforces.com/contest/1569/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define mod 1000000007
#define mod 998244353
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const ll cons = 200005;
ll fact[cons], invfact[cons];

ll mpow(ll a, ll n){ 
    a%=mod; ll res=1; 
    while(n>0){ 
        if(n&1LL)res=res*a%mod; a=a*a%mod; n>>=1; 
    } 
    return res; 
}

void pre(ll n){
    fact[0] = 1;
    ll i = 0;
    for(i=1; i<n; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    i--;
    invfact[i] = mpow(fact[i], mod-2);
    for(i--; i>=0; i--){
        invfact[i]=invfact[i+1]*(i+1)%mod;
    }
}

ll combination(ll n, ll r){
    if(n<r||n<0||r<0) return 0;
    if(r==0) return 1;
    return fact[n] * invfact[r] % mod * invfact[n-r] %mod;
}

ll multiply_with_mod(ll a, ll b){
    return ((a%mod)* (b%mod)) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    pre(cons);

    ll test; cin>>test;
    while(test--){
        ll n; cin>>n;
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin>>a[i];
        sort(a.begin(), a.end());
        if(a[n-1] == a[n-2]) cout << fact[n] << endl;
        else if(a[n-1] - a[n-2] != 1) cout << 0 << endl;
        else {
            ll second_max = a[n-2];
            ll cnt = 0;
            for(auto ele : a){
                if(ele == second_max) cnt+=1;
            }
            cout<<((fact[n]-multiply_with_mod(combination(n,cnt+1),multiply_with_mod((fact[n-cnt-1]),fact[cnt])))%mod+mod)%mod<<"\n";
        }
    }

    return 0;
}