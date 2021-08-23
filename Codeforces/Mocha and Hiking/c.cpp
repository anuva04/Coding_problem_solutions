// https://codeforces.com/problemset/problem/1559/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

void print(int l, int r){
    for(int i=l; i<=r; i++) cout << i << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++) cin>>arr[i];
        if(arr[1]==1){
            cout << n+1 << " ";
            print(1,n);
            cout << endl;
        } else if(arr[n]==0){
            print(1,n+1);
            cout << endl;
        } else {
            int i;
            for(i=1; i<=n-1; i++){
                if(arr[i]==0 && arr[i+1]==1) break;
            }
            if(i==n) cout << -1 << endl;
            else{
                print(1,i);
                cout << n+1 << " ";
                print(i+1,n);
                cout << endl;
            }
        }
    }
    return 0;
}