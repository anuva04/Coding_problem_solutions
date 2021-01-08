// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x,y,m;
    cin>>x>>y>>m;
    vector<int> xvec;
    vector<int> yvec;
    int ans=0;
    int i=0;
    while(ans <= m){
        xvec.push_back(ans);
        i+=1;
        ans = i*x;
    }
    ans = 0;
    i=0;
    while(ans <= m){
        yvec.push_back(ans);
        i+=1;
        ans = i*y;
    }
    int xlen = xvec.size();
    int ylen = yvec.size();
    int best = INT_MIN;
    for(int i=0; i<xlen; i++){
        for(int j=0; j<ylen; j++){
            if(xvec[i]+yvec[j]<=m){
                best = max(best, xvec[i]+yvec[j]);
            }
        }
    }
    cout << best;
    return 0;
}
