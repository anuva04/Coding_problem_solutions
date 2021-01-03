// https://codeforces.com/problemset/problem/1398/A

#include <iostream>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        if(arr[1]+arr[2]<=arr[n]){
            cout << 1 << " " << 2 << " " << n << endl;
        }else{
            cout << -1 <<endl;
        }
    }
    return 0;
}
