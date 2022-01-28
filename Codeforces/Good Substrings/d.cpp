// https://codeforces.com/problemset/problem/271/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    string s; cin>>s;
    string bin; cin>>bin;
    int k; cin>>k;

    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;

    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for(int i=1; i<n; i++) p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(n+1, 0);
    for(int i=0; i<n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1)*p_pow[i]) % m;

    int cnt = 0;
    for(int len=1; len<=n; len++){
        set<ll> hs;
        int bad = 0;
        for(int i=0; i<len; i++){
            // cout << i << " ::: " << bin[s[i]-'a'] << endl;
            if(bin[s[i]-'a'] == '0') bad+=1;
        }
        
        if(bad<=k){
            ll cur_hash = (h[len]+m-h[0])%m;
            cur_hash = (cur_hash*p_pow[n-1])%m;
            hs.insert(cur_hash);
        }
        // cout << len << " :: " << bad << endl;
        for(int i=1; i<=n-len; i++){
            if(bin[s[i+len-1]-'a'] == '0') bad+=1;
            if(bin[s[i-1]-'a'] == '0') bad-=1;
            if(bad>k) continue;
            ll cur_hash = (h[i+len]+m-h[i])%m;
            cur_hash = (cur_hash * p_pow[n-i-1])%m;
            hs.insert(cur_hash);
            // cout << i << ' ' << i+len-1 << ' ' << cur_hash << endl;
        }
        // cout << (int)hs.size() << endl;
        cnt += (int)hs.size();
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}