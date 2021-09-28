// https://codeforces.com/problemset/problem/1517/C

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

    // ll test; cin>>test;
    // while(test--){
        
    // }

    int n; cin>>n;
    int mat[n][n];
    memset(mat, 0, sizeof mat);
    for(int i=0; i<n; i++){
        cin>>mat[i][i];
    }
    for(int i=0; i<n; i++){
        int num = mat[i][i];
        int cnt = num - 1;
        int row = i, col = i;
        while(cnt > 0){
            if((col-1 >= 0) && (mat[row][col-1]==0)){
                col -= 1;
                mat[row][col] = num;
                cnt -= 1;
            }else{
                row += 1;
                mat[row][col] = num;
                cnt -= 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}