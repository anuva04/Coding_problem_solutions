// https://codeforces.com/contest/1569/problem/B
 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        int num_twos = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '2') num_twos += 1;
        }
        if(num_twos==1 || num_twos==2) cout << "NO" << endl;
        else {
            char mat[n][n];
            memset(mat,'=',sizeof mat);
            vector<int> two_idx;
            for(int i=0; i<n; i++){
                if(s[i] == '2') two_idx.push_back(i);
            }
            cout << "YES" << endl;
            for(int i=0; i<n; i++){
                mat[i][i] = 'X';
                if(s[i] == '1'){
                    for(int j=0; j<n; j++){
                        if(i==j) continue;
                        mat[i][j] = '=';
                        mat[j][i] = '=';
                    }
                }
            }
            
            for(int i=0; i<two_idx.size(); i++){
                if(i!=two_idx.size()-1){
                    mat[two_idx[i]][two_idx[i+1]]='+';
                    mat[two_idx[i+1]][two_idx[i]]='-';
                } else {
                    mat[two_idx[i]][two_idx[0]]='+';
                    mat[two_idx[0]][two_idx[i]]='-';
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++) cout << mat[i][j];
                cout << endl;
            }
        }
    }
 
    return 0;
}