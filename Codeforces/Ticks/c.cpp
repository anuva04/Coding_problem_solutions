// https://codeforces.com/problemset/problem/1579/C

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
        int n, m, k;
        cin>>n>>m>>k;
        char mat[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != '*') continue;
                int icen = i-1, jcen = j-1;
                int left = 0, right=0;
                bool f = false;
                while(icen>=0 && jcen>=0){
                    if((mat[icen][jcen] == '*') || (mat[icen][jcen] == '?')){ 
                        left += 1;
                        icen-=1;
                        jcen-=1;
                    }else break;
                }
                icen = i-1, jcen = j+1;
                while(icen>=0 && jcen<m){
                    if((mat[icen][jcen] == '*') || (mat[icen][jcen] == '?')){ 
                        right += 1;
                        icen-=1;
                        jcen+=1;
                    }else break;
                }

                // if(i==2 && j==2) cout << left << " " << right << endl;
                int m = min(left,right);

                if(m>=k){
                    mat[i][j] = '?';
                    int icen = i-1, jcen = j-1;
                    int m1=m;
                    while(m1--){
                        if((mat[icen][jcen] == '*') || (mat[icen][jcen] == '?')){ 
                            mat[icen][jcen] = '?';
                            icen-=1;
                            jcen-=1;
                        }else break;
                    }
                    m1 = m;
                    icen = i-1, jcen = j+1;
                    while(m1--){
                        if((mat[icen][jcen] == '*') || (mat[icen][jcen] == '?')){ 
                            mat[icen][jcen] = '?';
                            icen-=1;
                            jcen+=1;
                        }else break;
                    }
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << mat[i][j];
        //     }
        //     cout << endl;
        // }
        bool f = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '*'){
                    cout << "NO" << endl;
                    f = false;
                    break;
                }
            }
            if(!f) break;
        }
        if(f) cout << "YES" << endl;
    }
    
    return 0;
}