// https://www.codechef.com/problems/BOWLERS

#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        if(k>=n){
            for(int i=1; i<=n; i++) cout<<i<< " ";
            cout<<endl;
        }
        else if((k==1 && n!=1)|| k*l<n){
            cout<<-1<<endl;
        }else{
            int j=1;
            for(int i=0; i<n; i++){
                cout<<j<< " ";
                j++;
                if(j>k) j=1;
            }
            cout<<endl;
        }
    }
    return 0;
}
