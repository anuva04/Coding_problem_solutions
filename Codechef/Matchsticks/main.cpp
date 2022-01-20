// https://www.codechef.com/problems/MSTICK

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<ll> log_table;
vector<vector<ll>> min_st;
vector<vector<ll>> max_st;
vector<ll> matches;
ll n;

void build(ll n, ll k){
    min_st = vector<vector<ll>>(n, vector<ll>(k+1));
    max_st = vector<vector<ll>>(n, vector<ll>(k+1));

    for(ll i=0; i<n; i++) {
        min_st[i][0] = matches[i];
        max_st[i][0] = matches[i];
    }
    
    for(ll j=1; j<=k; j++){
        for(ll i=0; i+(1<<j)<=n; i++){
            min_st[i][j] = min(min_st[i][j-1], min_st[i+(1<<(j-1))][j-1]);
            max_st[i][j] = max(max_st[i][j-1], max_st[i+(1<<(j-1))][j-1]);
        }
    }
}

double getMin(ll l, ll r){
    if(l>=n || r<0) return -1;
    int j = log_table[r-l+1];
    int min_in_range = min(min_st[l][j], min_st[r-(1<<j)+1][j]);
    return min_in_range;
}

double getMax(ll l, ll r){
    if(l>=n || r<0) return -1;
    int j = log_table[r-l+1];
    int max_in_range = max(max_st[l][j], max_st[r-(1<<j)+1][j]);
    return max_in_range;
}

void solve(){
    cin>>n;
    matches.resize(n);
    for(ll i=0; i<n; i++) cin>>matches[i];

    log_table.resize(n+1);
    log_table[1] = 0;
    for(ll i=2; i<=n; i++) log_table[i] = log_table[i/2]+1;

    ll k = 25;
    build(n,k);

    ll q; cin>>q;
    ll l,r,j;
    while(q--){
        cin>>l>>r;
        double a = getMax(0, l-1);
        double b = getMin(l, r);
        double c = getMax(r+1, n-1);
        double ans1 = max(a,c)+b;
        double ans2 = (double)((getMax(l,r) - b)/2) + b;
        cout << fixed << setprecision(1) << max(ans1, ans2) << endl;
    }

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