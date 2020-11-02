#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    int ans=0;
    if(b<=c){
        ans = (b-a)+(d-c);
    }else if(d<=a){
        ans = (b-a)+(d-c);
    }else{
        int minx = min(a,min(b,min(c,d)));
        int maxx = max(a,max(b,max(c,d)));
        ans = maxx-minx;
    }
    cout<<ans;
    return 0;
}
