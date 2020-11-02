#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n+1], original[n+1];
        int num=-1, j;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            original[i]=i;
            if(arr[i]!= i){
                num = arr[i];
                j=i;
            }
        }
        if(num==-1){
            cout << "YES" <<endl;
        }else{
            int flag=1;
            for(int i=1; i<=n; i++){
                if(original[arr[i]]==i && __gcd(original[arr[i]],original[i])==arr[i]) original[i]=arr[i];
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1) cout << "YES" << endl;
            else cout << "NO" << endl;

        }
    }
    return 0;
}
