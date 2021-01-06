// https://cses.fi/problemset/task/1623/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solveRec(ll i, ll arr[], ll currSum, ll totalSum){
    if(i==0) return (abs(currSum - (totalSum-currSum)));

    return min(solveRec(i-1, arr, currSum, totalSum), solveRec(i-1, arr, currSum+arr[i-1], totalSum));
}

ll solve(ll arr[], ll n){
    ll totalSum = 0;
    for(ll i=0; i<n; i++) totalSum += arr[i];

    return solveRec(n, arr, 0, totalSum);
}

int main()
{
    ll n; cin>>n;
    ll arr[n];
    for(ll i=0; i<n; i++) cin>>arr[i];
    cout << solve(arr, n);

    return 0;
}
