// https://codeforces.com/problemset/problem/1537/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);
        int idx=0, diff=INT_MAX;
        for(int i=0; i<n-1; i++){
            if(arr[i+1]-arr[i]<diff){
                idx=i;
                diff = arr[i+1]-arr[i];
            }
        }
        cout << arr[idx] << " ";
        for(int i=idx+2; i<n; i++) cout << arr[i] << " ";
        for(int i=0; i<idx; i++) cout << arr[i] << " ";
        cout << arr[idx+1] << endl;
    }
}