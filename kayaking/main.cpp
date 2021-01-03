// https://codeforces.com/problemset/problem/863/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int arr[2*n];
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+(2*n));
    int min_diff = INT_MAX;
    for(int i=0; i<2*n-1; i++){
        for(int j=i+1; j<2*n; j++){
            vector<int> v;
            for(int k=0; k<2*n; k++){
                if(k!=i && k!=j) v.push_back(arr[k]);
            }
            int siz=v.size();
            int curr_diff=0;
            for(int k=0; k<siz-1; k+=2){
                curr_diff += (v[k+1]-v[k]);
            }
            min_diff = min(min_diff,curr_diff);
        }
    }
    cout << min_diff;
    return 0;
}
