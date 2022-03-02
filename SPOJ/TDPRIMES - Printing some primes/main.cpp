// https://www.spoj.com/problems/TDPRIMES/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n = 1e8;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for(int i=0; i<=n; i++) if(is_prime[i]) primes.push_back(i);
    for(int i=0; i<primes.size(); i+=100) cout << primes[i] << endl;
}

int main(){
        solve();
    
    return 0;
}