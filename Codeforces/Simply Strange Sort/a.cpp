// https://codeforces.com/contest/1561/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

void srt(vector<int>& arr, int n, bool isOdd){
    if(isOdd){
        for(int i=1; i<=n; i+=2){
            if(i+1<=n && arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        }
    } else {
        for(int i=2; i<=n; i+=2){
            if(i+1<=n && arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) cin>>arr[i];
        bool flag = false;
        int cnt = 0;
        bool isOdd = true;
        while(!flag){
            bool isSorted = true;
            for(int i=1; i<=n-1; i++){
                if(arr[i]>arr[i+1]){
                    isSorted = false;
                    break;
                }
            }
            if(isSorted){
                flag = true;
                break;
            }
            srt(arr, n, isOdd);
            cnt += 1;
            isOdd = !isOdd;
        }
        cout << cnt << endl;
    }
    return 0;
}