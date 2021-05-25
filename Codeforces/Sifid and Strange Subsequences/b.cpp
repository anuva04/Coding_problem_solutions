// https://codeforces.com/contest/1529/problem/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        int maxEle = INT_MIN;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        } 
        sort(arr.begin(), arr.end());
        maxEle = arr[0];
        int prevEle = arr[0];
        int minDiff = INT_MAX;
        int cnt = 1;
        for(int i=1; i<n; i++){
            int tempMaxEle = max(maxEle, arr[i]);
            int tempMinDiff = min(minDiff, abs(arr[i] - prevEle));
            if(tempMinDiff >= tempMaxEle){
                cnt += 1;
                maxEle = max(maxEle, arr[i]);
                minDiff = min(minDiff, abs(arr[i] - prevEle));
                prevEle = arr[i];
            }
        }
        cout << cnt << endl;
    }
}