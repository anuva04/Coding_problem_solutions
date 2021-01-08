// http://www.usaco.org/index.php?page=viewproblem2&cpid=891

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("shell.in","r",stdin);
    freopen("shell.out","w",stdout);
    int n; cin>>n;
    int mat[n][3];
    for(int i=0; i<n; i++){
        cin>>mat[i][0]>>mat[i][1]>>mat[i][2];
    }
    int start1=0;
    int ball_in=1;
    for(int i=0; i<n; i++){
        if(ball_in==mat[i][0]) ball_in=mat[i][1];
        else if(ball_in==mat[i][1]) ball_in=mat[i][0];
        if(mat[i][2]==ball_in) start1+=1;
    }
    int start2=0;
    ball_in=2;
    for(int i=0; i<n; i++){
        if(ball_in==mat[i][0]) ball_in=mat[i][1];
        else if(ball_in==mat[i][1]) ball_in=mat[i][0];
        if(mat[i][2]==ball_in) start2+=1;
    }
    int start3=0;
    ball_in=3;
    for(int i=0; i<n; i++){
        if(ball_in==mat[i][0]) ball_in=mat[i][1];
        else if(ball_in==mat[i][1]) ball_in=mat[i][0];
        if(mat[i][2]==ball_in) start3+=1;
    }
    cout<<max(start1,max(start2,start3));
    return 0;
}
