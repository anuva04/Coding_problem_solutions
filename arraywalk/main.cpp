#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ans=0;
        for(int i=0; i<=z; i++){

            int right=k-(2*i);
            if(right<0) continue;
            int sum=0, mx=0;
            for(int j=0; j<=right;j++){
                if(j<n-1){
                    mx = max(mx,arr[j]+arr[j+1]);
                }
                sum+=arr[j];
            }
            ans=max(ans,sum+mx*i);
        }
        cout <<ans<<endl;
    }
    return 0;
}
