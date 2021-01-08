// https://codeforces.com/contest/1399/problem/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int flag=1;
        for(int i=0; i<n-1; i++){
            int diff=arr[i+1]-arr[i];
            if(diff>1){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout << "YES" << endl;
        }else{
            cout << "NO" <<endl;
        }
    }
    return 0;
}
