// http://www.usaco.org/index.php?page=viewproblem2&cpid=568

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    int limit[n][2], bessie[m][2];
    for(int i=0; i<n; i++){
        cin>>limit[i][0]>>limit[i][1];
    }
    for(int i=0; i<m; i++){
        cin>>bessie[i][0]>>bessie[i][1];
    }
    int maxi=0;
    int limit_it=0, bessie_it=0;
    int bessie_dist = bessie[0][0];
    int limit_dist = limit[0][0];
    for(int i=1; i<=100; i++){
        if(i>limit_dist){
            limit_dist+=limit[limit_it+1][0];
            limit_it+=1;
        }
        if(i>bessie_dist){
            bessie_dist+=bessie[bessie_it+1][0];
            bessie_it+=1;
        }
        maxi = max(maxi, bessie[bessie_it][1]-limit[limit_it][1]);
    }
    cout<<maxi;
    return 0;
}
