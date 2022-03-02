// https://www.spoj.com/problems/HS08PAUL/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<bool> is_prime;
const int maxn = 1e8;
vector<int> primes;

void init(){
    is_prime.assign(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i <= maxn; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=maxn; j+=i) is_prime[j] = false;
        }
    }

    for(int i=1; i*i<maxn; i++){
        for(int j=1; j*j*j*j<maxn; j++) {
            if(i*i + j*j*j*j <= maxn && is_prime[i*i + j*j*j*j]) primes.push_back(i*i + j*j*j*j);
        }
    }

    sort(primes.begin(), primes.end());
    unique(primes.begin(), primes.end());
}

void solve(){
    int n; cin>>n;
    if(n == 1) cout << 0 << endl;
    else {
        int l = 0, h = primes.size()-1, m;
        while(l < h){
            m = (l+h+1)/2;
            if(primes[m] > n) h = m-1;
            else l = m;
        }
        cout << l+1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    init();

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