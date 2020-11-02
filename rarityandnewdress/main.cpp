#include <bits/stdc++.h>

using namespace std;
int minimum(int a, int b){
    if(a<b) return a;
    return b;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char board[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }
    //upperleft

      int upperleft[n][m];

      for(int k = 0; k < n; k++){
         for(int j = 0; j < m; j++){
            if(k == 0 || j == 0) upperleft[k][j] = 1;
            else {
               if(board[k-1][j] == board[k][j] && board[k][j-1] == board[k][j]){
                  upperleft[k][j] = min(upperleft[k-1][j],upperleft[k][j-1]) + 1;
               } else {
                  upperleft[k][j] = 1;
               }
            }
         }
      }

      //upper right

      int upperright[n][m];

      for(int k = 0; k < n; k++){
         for(int j = m-1; j >= 0; j--){
            if(k == 0 || j == m-1) upperright[k][j] = 1;
            else {
               if(board[k-1][j] == board[k][j] && board[k][j+1] == board[k][j]){
                  upperright[k][j] = min(upperright[k-1][j],upperright[k][j+1]) + 1;
               } else {
                  upperright[k][j] = 1;
               }
            }
         }
      }

      //down left

      int downleft[n][m];

      for(int k = n-1; k >= 0; k--){
         for(int j = 0; j < m; j++){
            if(k == n-1 || j == 0) downleft[k][j] = 1;
            else {
               if(board[k+1][j] == board[k][j] && board[k][j-1] == board[k][j]){
                  downleft[k][j] = min(downleft[k+1][j],downleft[k][j-1]) + 1;
               } else {
                  downleft[k][j] = 1;
               }
            }
         }
      }

      //down right

      int downright[n][m];

      for(int k = n-1; k >= 0; k--){
         for(int j = m-1; j >= 0; j--){
            if(k == n-1 || j == m-1) downright[k][j] = 1;
            else {
               if(board[k+1][j] == board[k][j] && board[k][j+1] == board[k][j]){
                  downright[k][j] = min(downright[k+1][j],downright[k][j+1]) + 1;
               } else {
                  downright[k][j] = 1;
               }
            }
         }
      }


      long long answer = 0;

      for(int k = 0; k < n; k++){
         for(int j = 0; j < m; j++){
            answer += (long)(min(min(upperleft[k][j],upperright[k][j]),min(downleft[k][j],downright[k][j])));
         }
      }

      cout<<answer<<endl;
    return 0;
}
