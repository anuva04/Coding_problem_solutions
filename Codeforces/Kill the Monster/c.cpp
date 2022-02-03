// https://codeforces.com/contest/1633/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    ll hc, dc; cin>>hc>>dc;
    ll hm, dm; cin>>hm>>dm;
    ll k, attack, health; cin>>k>>attack>>health;
    ll numc = (ll)ceil((ld)hc/dm);
    ll numm = (ll)ceil((ld)hm/dc);

    if(numm <= numc){
        cout << "YES" << endl;
        return;
    }

    for(ll a = 0; a<=k; a++){
        ll new_dc = dc + a*attack;
        ll new_hc = hc + (k-a)*health;

        numc = (ll)ceil((ld)new_hc/dm);
        numm = (ll)ceil((ld)hm/new_dc);
        if(numm <= numc){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}