// http://www.usaco.org/index.php?page=viewproblem2&cpid=639

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int max_diamonds = INT_MIN;
    int j;
    for(int i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(arr[j]-arr[i]>k) break;
        }
        max_diamonds = max(max_diamonds, j-i);
    }
    cout << max_diamonds;
    return 0;
}
