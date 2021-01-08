// http://www.usaco.org/index.php?page=viewproblem2&cpid=593

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int mat[2002][2002];
    for(int i=0; i<2002; i++){
        for(int j=0; j<2002; j++){
            mat[i][j]=-1;
        }
    }
    mat[1000][1000]=0;
    int n; cin>>n;
    int max_time = INT_MAX;
    int curr_time=0;
    int x=1000, y=1000;
    for(int i=0; i<n; i++){
        char d; cin>>d;
        int s; cin>>s;
        if(d=='E'){
            for(int j=0; j<s; j++){
                curr_time+=1;
                y+=1;
                if(mat[x][y]!=-1){
                    max_time = min(max_time, abs(mat[x][y]-curr_time));
                }
                mat[x][y]=curr_time;
            }
        }else if(d=='W'){
            for(int j=0; j<s; j++){
                curr_time+=1;
                y-=1;
                if(mat[x][y]!=-1){
                    max_time = min(max_time, abs(mat[x][y]-curr_time));
                }
                mat[x][y]=curr_time;
            }
        }else if(d=='N'){
            for(int j=0; j<s; j++){
                curr_time+=1;
                x+=1;
                if(mat[x][y]!=-1){
                    max_time = min(max_time, abs(mat[x][y]-curr_time));
                }
                mat[x][y]=curr_time;
            }
        }else if(d=='S'){
            for(int j=0; j<s; j++){
                curr_time+=1;
                x-=1;
                if(mat[x][y]!=-1){
                    max_time = min(max_time, abs(mat[x][y]-curr_time));
                }
                mat[x][y]=curr_time;
            }
        }
    }
    if(max_time==INT_MAX) cout<< -1;
    else cout<<max_time;
    return 0;
}
