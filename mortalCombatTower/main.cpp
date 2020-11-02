#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans=0;
        if(arr[0]==1) ans+=1;
        for(int i=1; i<n; i++){
            if(arr[i]==0) continue;
            int j=i;
            while(j<n && arr[j]==1) ++j;
            ans += (j-i)/3;
            i=j-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
