#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum(ll n){
    return n*(n+1)/2;
}
int main()
{
    int t; cin>>t;
    while(t--){
        ll cell;
        cin>>cell;
        ll res=0;
        ll height=1;
        ll cells_used=0;
        while(cells_used<=cell){
            height = height*2;
            cells_used += sum(height-1);
            res+=1;
        }
        cout<<res-1<<endl;
    }
    return 0;
}
