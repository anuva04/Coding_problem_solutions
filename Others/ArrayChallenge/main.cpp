#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int arrayChallenge(vector<int> arr){
    int n1 = arr.size();
    int n = arr[0];
    bool arr1[n+1] = {0};

    for(int i=1; i<n1; i++){
        arr1[arr[i]]=true;
    }

    int cnt=0;
    for(int i=1; i<n; i++){
        if(i%2==1 && arr1[i]==false && arr1[i+1]==false) cnt++;
        if(i!=1 && i!=2 && arr1[i]==false && arr1[i-2]==false) cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int val; cin>>val; arr.push_back(val);
    }
    int ans = arrayChallenge(arr);
    cout << ans;
    return 0;
}
