// https://cses.fi/problemset/task/1624

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(int y, int &cnt, char board[8][8], int column[8], int diag1[16], int diag2[16]){
    if(y==8){
        cnt++;
        return;
    }
    for(int x=0; x<8; x++){
        if(column[x] || diag1[x+y] || diag2[x-y+8-1] || board[y][x]=='*') continue;
        column[x] = diag1[x+y] = diag2[x-y+8-1] = 1;
        solve(y+1, cnt, board, column, diag1, diag2);
        column[x] = diag1[x+y] = diag2[x-y+8-1] = 0;
    }
}
int main()
{
    char board[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>board[i][j];
        }
    }
    int column[8]={0}, diag1[16]={0}, diag2[16]={0};
    int cnt=0;
    solve(0, cnt, board, column, diag1, diag2);
    cout << cnt;
    return 0;
}
