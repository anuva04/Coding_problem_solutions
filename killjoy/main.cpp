#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        int flag=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]!=x) flag=1;
        }
        if(flag==0){
            cout<<0<<endl;
        }else{
            flag=0;
            int sum=0;
            for(int i=0; i<n; i++){
                if(arr[i]==x){
                    flag=1;
                }
                sum = sum + arr[i] - x;
            }
            if(flag==1 || sum==0) cout<<1<<endl;
            else{
                cout<<2<<endl;
            }
        }

    }
    return 0;
}
