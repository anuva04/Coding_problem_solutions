#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a, a);
}

int main(){
    vector<ll> sq;
    vector<ll> ap;
    sq.push_back(0);
    ap.push_back(0);
    for(ll i=1; i<=1000005; i++){
        sq.push_back(i*i);
        ap.push_back((2*i)+1);
    }
    ll t; cin>>t;
    while(t--){
        ll k; cin>>k;
        ll sum=0;
        for(ll i=1; i<=2*k; i++){
            //cout << gcd(ap[i], k+sq[i]) << endl;
            sum += gcd(ap[i], k+sq[i]);
        }
        cout << sum << endl;
    }
}