// http://www.usaco.org/index.php?page=viewproblem2&cpid=616

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n, total_cows=0; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        total_cows+=arr[i];
    }
    int min_dist=INT_MAX, curr_dist=0, curr_cow;
    int curr_door;
    for(curr_door=0; curr_door<n; curr_door++){
        curr_dist=0;
        curr_cow = total_cows;
        for(int j=curr_door; j<n; j++){
            curr_cow-=arr[j];
            curr_dist+=curr_cow;
        }
        for(int j=0; j<curr_door; j++){
            curr_cow-=arr[j];
            curr_dist+=curr_cow;
        }
        if(curr_dist<min_dist) min_dist=curr_dist;
    }
    cout << min_dist;
    return 0;
}
