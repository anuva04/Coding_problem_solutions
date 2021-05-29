// https://codeforces.com/contest/1526/problem/A

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[2*n];
        for(int i=0; i<2*n; i++) cin>>arr[i];
        // bool f = true;
        // for(int i=0; i<=2*n-2; i++){
        //     if(f){
        //         if(arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        //     } else {
        //         if(arr[i]<arr[i+1]) swap(arr[i], arr[i+1]);
        //     }
        //     f = !f;
        // }
        sort(arr, arr+2*n);
        for(int i=1; i<2*n&&(i+2)<2*n; i+=2){
            swap(arr[i], arr[i+1]);
        }
        for(int i=0; i<2*n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}