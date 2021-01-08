#include <bits/stdc++.h>

using namespace std;
int solve(int x){
    int countt, y;
    if(x<9) countt=1;
    else if(x%9==0){
        countt=(x/9);
    }else{
        y=ceil(x/9);
        countt=y+1;
    }
    return countt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int pc,pr;
        cin>>pc>>pr;
        if(solve(pc)<solve(pr)){
            cout << 0 << " " << solve(pc) <<endl;
        }else{
            cout << 1 << " " << solve(pr) <<endl;
        }
    }
    return 0;
}
