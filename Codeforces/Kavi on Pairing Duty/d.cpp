// https://codeforces.com/contest/1529/problem/D

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 998244353;
int divisors[1000005];

void find_divisors(int n){
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            divisors[j]+=1;
            divisors[j] %= mod;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    find_divisors(n);
    vector<int> dp(2*n+1);
    vector<int> prefix_sum(2*n+1);
    dp[0] = 1;
    prefix_sum[0] = 1;
    for(int i=2; i<=2*n; i+=2){
        dp[i] = prefix_sum[i-2] + (divisors[i/2]-1);
        dp[i] %= mod;
        prefix_sum[i] = prefix_sum[i-2]+dp[i];
        prefix_sum[i] %= mod;
    }
    cout << dp[2*n] << endl;
    return 0;
}