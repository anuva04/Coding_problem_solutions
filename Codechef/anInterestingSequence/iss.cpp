// https://www.codechef.com/MAY21B/problems/ISS
// partial solution

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main(){
    int t; cin>>t;
    while(t--){
        ll k; cin>>k;
        vector<ll> v(2*k + 2);
        ll sq=1;
        for(int i=1; i<=(2*k+1); i++){
            v[i] = sq*sq;
            sq+=1;
        }
        for(int i=1; i<=(2*k+1); i++) v[i] += k;
        ll sum=0;
        int idx=1;
        for(int i=0; i<2*k; i++){
            ll g = gcd(v[idx], v[idx+1]);
            //cout << g << "***" << endl;
            sum += g;
            idx+=1;
        }
        cout << sum << endl;
    }
}