#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll sum=0;
    for(int x=1; x<=10000; x++){
        for(int y=1; y<=10000; y++){
            int x3 = x*x*x;
            int y3 = y*y*y;
            int x2 = x*x;
            int y2 = y*y;
            int xy = 42*x*y;
            if(x3+y3-x2-y2-xy == 0){
                cout << x << " " << y << endl;
                sum += (x+y);
            }
        }
    }
    cout << sum;
    return 0;
}
