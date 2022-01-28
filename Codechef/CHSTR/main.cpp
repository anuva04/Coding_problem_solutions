// https://www.codechef.com/problems/CHSTR

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int ans[5005];
int cnt[5005];
int cnt2[5005];

int fact[5005];
int inv[5005];
 
int bin_pow(int o, int s) {
    if (s == 0) return 1;
    if (s == 1) return o % mod;
    int d = bin_pow(o, s/2);
    d = (d * 1ll * d) % mod;
    if (s % 2 == 1)
        d = (d * 1ll * o) % mod;
    return d;
}
 
int C(int n, int k) {
    int res = 1;
    res = (res * 1ll * fact[n]) % mod;
    res = (res * 1ll * inv[k]) % mod;
    res = (res * 1ll * inv[n-k]) % mod;
    
    return res;
}

vector<int> z_function (string s) {
    int n = (int) s.length();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

void solve(){
    int n,q; cin>>n>>q;
    string s; cin>>s;
    fact[0] = 1, inv[0] = 1, ans[0] = 0;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1] * 1ll * i) % mod;
        inv[i] = bin_pow(fact[i], mod-2);
        ans[i] = 0;
        cnt[i] = 0;
    }
    for(int i=0; i<n; i++){
        vector<int> z = z_function(s.substr(i, n-i));
        for(int i=0; i<=n; i++) cnt2[i] = 0;
        for(auto num : z){
            cnt2[0]++;
            cnt2[num+1]--;
        }
        for(int i=1; i<=n; i++){
            cnt2[i] += cnt2[i-1];
            cnt[cnt2[i]]++;
        }
        ans[1] += (n-i);
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            ans[j+1] += (cnt[i] * 1LL * C(i, j)) % mod;
            ans[j+1] %= mod;
        }
    }
    int k;
    while(q--){
        cin>>k;
        if(k>n) cout << 0 << endl;
        else cout << ans[k] << endl;
    }
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