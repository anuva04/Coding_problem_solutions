// https://codeforces.com/contest/1516/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        int l = 0, r = n-1;
        while(k>0 && l<r){
            if(arr[l]==0){
                l+=1;
                continue;
            }
            if(l==r) break;
            if(k<=arr[l]){
                arr[l]-=k;
                arr[r]+=k;
                k=0;
                break;
            }else{
                arr[r]+=arr[l];
                k-=arr[l];
                arr[l]=0;
                l+=1;
            }
        }
        for(auto ele : arr) cout << ele << " "; cout << endl;
    }
    
    return 0;
}