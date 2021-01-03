// http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;
int arr[10][20];
int solve(int a, int b){
    int ans = 0;
    for(int session=0; session<k; session++){
        int apos, bpos;
        for(int i=0; i<n; i++){

            if(arr[session][i]==a) apos = i;
            if(arr[session][i]==b) bpos = i;
        }
        if(apos<bpos) ans++;
    }
    return ans;
}
int main()
{
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin>>k>>n;

    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int res=0;
    for(int a=1; a<=n; a++){
        for(int b=1; b<=n; b++){
            if(solve(a,b)==k){
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
