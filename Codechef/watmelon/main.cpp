// https://www.codechef.com/problems/WATMELON

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        int sum = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        if(n==1){
            if(arr[0]<0) cout<<"NO"<<endl;
            else cout << "YES" <<endl;
        }else if(n==2){
            if(arr[0]>=0 && arr[1]>=0){
                cout << "YES" << endl;
            }else{
                if(arr[0]<0){
                    if(abs(arr[0])>arr[1]) cout << "NO" << endl;
                    else cout << "YES" << endl;
                }else if(arr[1]<0){
                    if(abs(arr[1])>arr[0]) cout << "NO" << endl;
                    else cout << "YES" << endl;
                }
            }
        }else{
            if(sum>=0) cout << "YES";
            else cout << "NO" << endl;
        }
    }
    return 0;
}
