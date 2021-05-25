// https://codeforces.com/contest/1529/problem/A

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);
        int cnt=1;
        for(int i=1; i<n; i++){
            if(arr[i]==arr[i-1]) cnt+=1;
            else break;
        }
        int ans = n-cnt;
        cout << ans << endl;
    }
    return 0;
}