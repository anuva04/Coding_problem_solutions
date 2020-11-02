#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int t; cin>>t;
    while(t--){
        ll a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        ll a1=a, b1=b, n1=n;
        ll ans, ans1;
        if(a-x > n){
            a=a-n;
        }else{
            n=n-(a-x);
            a=x;

            if(n>0){
                if(b-y > n){
                    b=b-n;
                }else{
                    b=y;
                }
            }
        }
        ans = a*b;
        if(b1-y > n1){
            b1=b1-n1;
        }else{
            n1=n1-(b1-y);
            b1=y;

            if(n1>0){
                if(a1-x > n1){
                    a1=a1-n1;
                }else{
                    a1=x;
                }
            }
        }
        //cout << a << " " << b << endl;
        //cout << "******************" <<endl;
        //cout << a1 << " " << b1 << endl;
        //cout << "******************" <<endl;
        ans1 = a1*b1;
        cout<<min(ans,ans1)<<endl;
    }
    return 0;
}
