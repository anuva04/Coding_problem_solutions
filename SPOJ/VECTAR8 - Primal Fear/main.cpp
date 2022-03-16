// https://www.spoj.com/problems/VECTAR8/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<bool> is_prime;
const int maxn = 1e7;

vector<int> cnt;

bool hasZero(int n){
    while(n){
        if(n%10 == 0) return true;
        n /= 10;
    }
    return false;
}

vector<int> suffixes(int n){
    vector<int> res;
    int div = 10;
    while(div < n){
        res.push_back(n%div);
        div *= 10;
    }
    res.push_back(n);
    return res;
}

void init(){
    is_prime.assign(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i <= maxn; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=maxn; j+=i) is_prime[j] = false;
        }
    }
    cnt.assign(maxn, 0);
    for(int i=2; i<=maxn; i++){
        cnt[i] = cnt[i-1];
        if(!is_prime[i]) continue;
        if(hasZero(i)) continue;
        vector<int> suf = suffixes(i);
        bool ok = true;
        for(int ele : suf){
            if(!is_prime[ele]) {
                ok = false;
                break;
            }
        }
        
        if(ok) cnt[i]++;
    }
}

void solve(){
    int n; cin>>n;
    cout << cnt[n] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    init();

    // for(auto ele : feared_primes) cout << ele << ' '; cout << endl;

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