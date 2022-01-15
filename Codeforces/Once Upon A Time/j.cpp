// https://codeforces.com/gym/100963/attachments

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

ll extendedGCD(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll g = extendedGCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return g;
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    ll n, m, a, k;
    while(true){
        // our equation is:
        // n + m*xg = (k+a) + a*yg
        // => a*yg - m*xg = n - (k+a)
        // we need to find (xg, yg) such that n + m*xg is the first time when man and woman shake hands
        // hence xg needs to be just less than 0 and corresponding yg will be just more than 0
        cin>>n>>m>>a>>k;
        if(n==0 && m==0 && a==0 && k==0) return 0;
        k += a;
        // to make sure k is always greater than n
        if(k<n) swap(k, n), swap(a, m);
        ll xg, yg;

        ll gcd = extendedGCD(a, m, xg, yg);
        ll separation = k-n;
        if(separation%gcd != 0){
            cout << "Impossible\n";
            continue;
        }
        xg *= separation/gcd;
        yg *= separation/gcd;
        // shifting xg and yg such that xg is just less than 0
        if(xg>0){
            ll cnt = (xg*gcd + m)/m;
            xg -= cnt*m/gcd;
            yg += cnt*a/gcd;
        } else {
            ll cnt = (-xg*gcd)/m;
            xg += cnt*m/gcd;
            yg -= cnt*a/gcd;
        }
        ll first_meet_time = n + yg*m;
        cout << first_meet_time << endl;
    }
    
    return 0;
}