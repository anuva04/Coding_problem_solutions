// https://codeforces.com/psroblemset/problem/1525/B

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n+1);
        bool isSorted = true;
        for(int i=1; i<=n; i++){
            cin>>arr[i];
            if(i!=arr[i]) isSorted=false;
        }
        if(isSorted) cout << 0 << endl;
        else if(arr[1]==1 || arr[n]==n) cout << 1 << endl;
        else if(arr[n]==1 && arr[1]==n) cout << 3 << endl;
        else cout << 2 << endl;
    }

    return 0;
}