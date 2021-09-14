// https://codeforces.com/problemset/problem/1520/C

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
        if(n==1) {
            cout << 1 << endl;
            continue;
        }
        if(n==2) {
            cout << -1 << endl;
            continue;
        }
        int mat[n][n];
        int curr_num = n+1;
        int i=0, j=1;
        int diagonal = n-1;
        for(int ii = 0; ii<n; ii++){
            mat[ii][ii] = ii+1;
        }
        while(true){
            int streak = diagonal;
            int curr_i = i;
            int curr_j = j;
            while(streak--){
                mat[curr_i][curr_j] = curr_num;
                curr_num += 1;
                curr_i += 1;
                curr_j += 1;
            }
            curr_i = j;
            curr_j = i;
            streak = diagonal;
            while(streak--){
                mat[curr_i][curr_j] = curr_num;
                curr_num += 1;
                curr_i += 1;
                curr_j += 1;
            }
            if(curr_num > (n*n)) break;
            diagonal -= 1;
            j+=1;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}