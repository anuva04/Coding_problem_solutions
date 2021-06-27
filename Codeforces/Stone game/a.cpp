// https://codeforces.com/problemset/problem/1538/A
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        int min_number=INT_MAX, max_number = INT_MIN, min_idx =  -1, max_idx = -1;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if(arr[i]<min_number){
                min_number = arr[i];
                min_idx = i;
            }
            if(arr[i]>max_number){
                max_number = arr[i];
                max_idx = i;
            }
        }
        int left = min(min_idx, max_idx);
        int right = max(min_idx, max_idx);
        int ans = min(right+1, min(n-left, left+1+n-right));
        cout << ans << endl;

    }
    return 0;
}