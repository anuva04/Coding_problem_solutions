// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4672b

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

void solve(){
    vector<vector<int>> v(3, vector<int>(4));
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++) cin>>v[i][j];
    }
    for(int i=0; i<4; i++){
        v[0][i] = min(v[0][i], min(v[1][i], v[2][i]));
    }
    ll sum = 0;
    for(int i=0; i<4; i++) sum += v[0][i];
    if(sum < 1e6) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int rem = 1e6;
    for(int i=0; i<4; i++){
        cout << min(rem, v[0][i]) << ' ';
        rem -= min(rem, v[0][i]);
    } cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test; cin>>test;

    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}