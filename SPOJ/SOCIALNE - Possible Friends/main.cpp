// https://www.spoj.com/problems/SOCIALNE/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    vector<string> mat;
    string s; cin>>s;
    int m = s.size();
    mat.push_back(s);
    for(int i=0; i<m-1; i++){
        cin>>s;
        mat.push_back(s);
    }
    vector<vector<int>> d(m, vector<int>(m, INF));
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 'Y') d[i][j] = 1;
            if(i == j) d[i][j] = 0;
        }
    }
    for(int k=0; k<m; ++k){
        for(int i=0; i<m; ++i){
            for(int j=0; j<m; ++j) {
                if(d[i][k] < INF && d[k][j] < INF) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int id = 0, friends = 0;
    for(int i=0; i<m; i++){
        int cnt = 0;
        for(int j=0; j<m; j++) {
            // cout << d[i][j] << ' ';
            if(i == j) continue;
            if(d[i][j] == 2) cnt++;
        }
        // cout << endl;
        if(cnt > friends){
            id = i;
            friends = cnt;
        }
    }
    cout << id << ' ' << friends << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}