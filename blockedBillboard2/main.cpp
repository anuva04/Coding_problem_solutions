#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool pointsCovered(int x, int y, int x1, int y1, int x2, int y2){
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
}
int main()
{
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int deli_x1, deli_y1, deli_x2, deli_y2;
    int lawn_x1, lawn_y1, lawn_x2, lawn_y2;
    cin>>lawn_x1>>lawn_y1>>lawn_x2>>lawn_y2;
    cin>>deli_x1>>deli_y1>>deli_x2>>deli_y2;
    int num=0;
    if(pointsCovered(lawn_x1,lawn_y1, deli_x1, deli_y1, deli_x2, deli_y2)) num+=1;
    if(pointsCovered(lawn_x2,lawn_y1, deli_x1, deli_y1, deli_x2, deli_y2)) num+=1;
    if(pointsCovered(lawn_x2,lawn_y2, deli_x1, deli_y1, deli_x2, deli_y2)) num+=1;
    if(pointsCovered(lawn_x1,lawn_y2, deli_x1, deli_y1, deli_x2, deli_y2)) num+=1;

    if(num<2) cout << (lawn_x2-lawn_x1)*(lawn_y2-lawn_y1);
    else if(num==4) cout << 0;
    else{
        int xl = max(lawn_x1,deli_x1);
        int xr = min(lawn_x2,deli_x2);
        int yt = min(lawn_y2,deli_y2);
        int yb = max(lawn_y1,deli_y1);
        cout << (lawn_x2-lawn_x1)*(lawn_y2-lawn_y1) - (xr-xl)*(yt-yb);
    }
    return 0;
}
