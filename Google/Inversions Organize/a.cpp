// https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a33e95

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<string> mat(2*n);
    for(int i=0; i<2*n; i++) cin>>mat[i];
    int tlo = 0, tli = 0, tro = 0, tri = 0, blo = 0, bli = 0, bro = 0, bri = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 'I') tli++;
            else tlo++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=n; j<2*n; j++){
            if(mat[i][j] == 'I') tri++;
            else tro++;
        }
    }
    for(int i=n; i<2*n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 'I') bli++;
            else blo++;
        }
    }
    for(int i=n; i<2*n; i++){
        for(int j=n; j<2*n; j++){
            if(mat[i][j] == 'I') bri++;
            else bro++;
        }
    }
    int cnt = 0;
    // cout << tli << ' ' << bri << ' ' << tri << ' ' << bli << endl;
    if(tli != bri){
        cnt += abs(tli - bri);
    }
    if(tri != bli) cnt += abs(tri - bli);
    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll test; cin>>test;

    for(ll t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}