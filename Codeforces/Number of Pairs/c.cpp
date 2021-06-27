// https://codeforces.com/problemset/problem/1538/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int arr[], int l, int r, int n){
    int cnt=0;
    int i = 0, low = n-1, high = n-1;
    while(i<high){
        low = max(i,low);
        while (low > i && arr[i] + arr[low] >= l) --low;
        while (high > low && arr[i] + arr[high] > r) --high; 
        cnt += (high-low);
        ++i;
    }
    return cnt;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n, l, r; cin>>n>>l>>r;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr, arr+n);
        cout << solve(arr, l, r, n) << endl;
    }
    return 0;
}