// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

const int max_val = 2e6 + 7;

void solve(){
    ll n, d, c, m;
    cin>>n>>d>>c>>m;
    string s; cin>>s;
    ll i=0;
    for(i=0; i<n; i++){
        if(s[i]=='D'){
            if(d<=0){
                break;
            } else{ c += m; d-=1;}
        }
        if(s[i] == 'C'){
            if(c<=0){
                break;
            } else{ c -= 1;}
        }
    }
    // cout << i << " ";
    bool foundDog = false;
    for(ll j=i; j<n; j++){
        if(s[j] == 'D'){
            foundDog = true;
            break;
        }
    }
    if(foundDog) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}