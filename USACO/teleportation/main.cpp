// http://www.usaco.org/index.php?page=viewproblem2&cpid=807

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a>b){
        int temp=a;
        a=b;
        b=temp;
    }
    if(a==b || x==y){
        cout<< b-a;
    }else{
        int original_dist = b-a;
        int a_dist, b_dist;
        if(abs(a-x)<abs(a-y)){
            a_dist = abs(a-x);
            b_dist = abs(b-y);
        }else{
            a_dist = abs(a-y);
            b_dist = abs(b-x);
        }
        if(original_dist<(a_dist+b_dist)) cout << original_dist;
        else cout << (a_dist+b_dist);
    }
    return 0;
}
