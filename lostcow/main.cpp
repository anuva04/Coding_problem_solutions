#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin>>x>>y;
    int curr_pos = x;
    int prev_pos = x;
    int dist=0;
    if(x>y){
        int parity=0;
        int factor=1;
        while(curr_pos>y){
            if(parity==0){
                curr_pos=x+factor;
                parity=1;
            }else{
                curr_pos=x-factor;
                parity=0;
            }
            factor=factor*2;
            dist = dist + abs(curr_pos-prev_pos);
            prev_pos = curr_pos;
        }
    }else if(x<y){
        int parity=0;
        int factor=1;
        while(curr_pos<y){
            if(parity==0){
                curr_pos=x+factor;
                parity=1;
            }else{
                curr_pos=x-factor;
                parity=0;
            }
            factor=factor*2;
            dist = dist + abs(curr_pos-prev_pos);
            prev_pos = curr_pos;
        }
    }else{
        dist = 0;
    }
    dist = dist-abs(curr_pos-y);
    cout << dist;
    return 0;
}
