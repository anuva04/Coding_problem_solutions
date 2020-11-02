#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a<b) swap(a,b);
        int ans = a-b;
        int res=ans/10;
        if(ans%10==0) cout<<res<<endl;
        else cout<<res+1<<endl;
    }
    return 0;
}
