#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        int flag=1;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]>k) flag=0;
        }
        int ans=0;
        if(flag==0) cout << -1 <<endl;
        else{
            int i=0;
            int sum=0;
            while(i<n){
                while(sum<k && i<n){
                    sum+=arr[i];
                    i++;
                }
                ans++;
                sum=0;
            }
            cout<<ans<<endl;
            }
    }
    return 0;
}
