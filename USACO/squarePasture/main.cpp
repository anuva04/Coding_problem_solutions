// http://www.usaco.org/index.php?page=viewproblem2&cpid=663

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x11, y11, x21, y21;
    cin>>x11>>y11>>x21>>y21;
    int x12, y12, x22, y22;
    cin>>x12>>y12>>x22>>y22;
    int x_left, x_right, y_top, y_bottom;
    x_left = min(x11,x12);
    x_right = max(x21,x22);
    y_top = max(y21,y22);
    y_bottom = min(y11,y12);
    int side = max(abs(x_left-x_right),abs(y_top-y_bottom));
    cout << (side*side);
    return 0;
}
