#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;

    if(x3<=x1 && x4>=x2 && y3<=y1 && y4>=y2) cout << "NO";
    else if(x5<=x1 && x6>=x2 && y5<=y1 && y6>=y2) cout << "NO";
    else if(x3<=x1 && x4>=x2 && x5<=x1 && x6>=x2 && y3<=y1 && y6>=y2 && y4>=y5) cout << "NO";
    else if(x3<=x1 && x4>=x2 && x5<=x1 && x6>=x2 && y5<=y1 && y4>=y2 && y6>=y3) cout << "NO";
    else if(y3<=y1 && y4>=y2 && y5<=y1 && y6>=y2 && x3<=x1 && x6>=x2 && x4>=x5) cout << "NO";
    else if(y3<=y1 && y4>=y2 && y5<=y1 && y6>=y2 && x5<=x1 && x4>=x2 && x6>=x3) cout << "NO";
    else cout << "YES";
    return 0;
}
