// https://codeforces.com/contest/1609/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int mx = 1000001;
bool used[mx], prime[mx];

void findPrimes(){
    for(int i=2; i<mx; i++){
        if(!used[i]){
            prime[i] = true;
            for(int j=i; j<mx; j+=i) used[j] = true;
        }
    }
}

void solve(){
    int n, e;
    cin>>n>>e;
    vector<int> isOne(n+1, false), isPrime(n+1, false);
    int num;
    for(int i=1; i<=n; i++){
        cin>>num;
        if(num == 1) isOne[i] = true;
        else if(prime[num]) isPrime[i] = true;
    }

    vector<int> len_of_consecutive_ones;
    vector<bool> taken(n+1, false);

    ll ans = 0;

    for(int i=1; i<=n; i++){
        len_of_consecutive_ones.clear();
        int num_ones = 0;
        for(int j=i; j<=n; j+=e){
            if((!isOne[j] && !isPrime[j]) || taken[j]) break;
            taken[j] = true;
            if(isOne[j]) num_ones += 1;
            else {
                len_of_consecutive_ones.push_back(num_ones);
                num_ones = 0;
            }
        }
        if((int)len_of_consecutive_ones.size() == 0) continue;
        len_of_consecutive_ones.push_back(num_ones);
        for(int j=0; j<len_of_consecutive_ones.size(); j++){
            ans += len_of_consecutive_ones[j];
            if(j>0 && j<len_of_consecutive_ones.size()-1) ans += len_of_consecutive_ones[j];
            if(j<len_of_consecutive_ones.size()-1){
                ans += (ll)(len_of_consecutive_ones[j])*(ll)(len_of_consecutive_ones[j+1]);
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    findPrimes();
    cout << endl;
    
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