// http://www.usaco.org/index.php?page=viewproblem2&cpid=739

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
string spotty[500], plain[500];
int spotty_int[500][50], plain_int[500][50], res[64];
int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

//    int n, m;
    cin>>n>>m;
//    string spotty[n], plain[n];
//    int spotty_int[n][m], plain_int[n][m], res[64];

    for(int i=0; i<n; i++){
        cin>>spotty[i];

        for(int j=0; j<m; j++){
            if (spotty[i][j]=='A') spotty_int[i][j] = 0;
            else if (spotty[i][j]=='C') spotty_int[i][j] = 1;
            else if (spotty[i][j]=='G') spotty_int[i][j] = 2;
            else if (spotty[i][j]=='T') spotty_int[i][j] = 3;
        }
    }
    for(int i=0; i<n; i++){
        cin>>plain[i];

        for(int j=0; j<m; j++){
            if (plain[i][j]=='A') plain_int[i][j] = 0;
            else if (plain[i][j]=='C') plain_int[i][j] = 1;
            else if (plain[i][j]=='G') plain_int[i][j] = 2;
            else if (plain[i][j]=='T') plain_int[i][j] = 3;
        }
    }

    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            for(int k=j+1; k<m; k++){
                bool ok = true;
                for(int l=0; l<n; l++) res[spotty_int[l][i]*16 + spotty_int[l][j]*4 + spotty_int[l][k]] = 1;
                for(int l=0; l<n; l++){
                    if(res[plain_int[l][i]*16 + plain_int[l][j]*4 + plain_int[l][k]] == 1) ok = false;
                }
                for(int l=0; l<n; l++) res[spotty_int[l][i]*16 + spotty_int[l][j]*4 + spotty_int[l][k]] = 0;

                if(ok) cnt+=1;
            }
        }
    }
    cout << cnt;
    return 0;
}
