#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int h, p;
        cin>>h>>p;
        while(h>0 && p>0){
            h=h-p;
            p=p/2;
        }
        if(p<=0 && h>0) cout << 0 <<endl;
        else cout << 1 <<endl;
    }
    return 0;
}
