// http://www.usaco.org/index.php?page=viewproblem2&cpid=939

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    char mat[10][10];
    int barn_x, barn_y, lake_x, lake_y, rock_x, rock_y;
    int ans;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>mat[i][j];
            if(mat[i][j]=='B'){
                barn_x = i;
                barn_y = j;
            }else if(mat[i][j]=='L'){
                lake_x=i;
                lake_y=j;
            }else if(mat[i][j]=='R'){
                rock_x=i;
                rock_y=j;
            }
        }
    }
    if(barn_x==lake_x){
        if(rock_x==barn_x && ((rock_y>barn_y && rock_y<lake_y) || (rock_y<barn_y && rock_y>lake_y))){
            ans = abs(barn_y-lake_y)+1;
        }else{
            ans = abs(barn_y-lake_y)-1;
        }
    }else if(barn_y==lake_y && ((rock_x>barn_x && rock_x<lake_x) || (rock_x<barn_x && rock_x>lake_x))){
        if(rock_y==barn_y){
            ans = abs(barn_x-lake_x)+1;
        }else{
            ans = abs(barn_x-lake_x)-1;
        }
    }else{
        ans = abs(barn_x-lake_x)+abs(barn_y-lake_y)-1;
    }
    cout<<ans;
    return 0;
}
