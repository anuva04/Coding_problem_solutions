// https://codeforces.com/problemset/problem/1419/A

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string num; cin>>num;
        if(n%2 == 0){
            int flag=0;
            for(int i=1; i<n; i+=2){
                if((num[i]-'0')%2==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<1<<endl;
            else cout<<2<<endl;
        }else{
            int flag=0;
            for(int i=0; i<n; i+=2){
                if((num[i]-'0')%2!=0){
                    flag=1;
                    break;
                }
            }
            if(flag==1) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
    return 0;
}
