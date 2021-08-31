// https://codeforces.com/problemset/problem/1557/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n, k; cin>>n>>k;
        vector<int> arr(n);
        vector<int> sorted_arr(n);
        for(int i=0; i<n; i++){
            int x; cin>>x;
            arr[i] = x; // 1 -4 0 -2
            sorted_arr[i] = x; // -4 -2 0 1
        }
        sort(sorted_arr.begin(), sorted_arr.end());
        map<int,int> ele_idx;
        for(int i=0; i<n; i++){
            ele_idx[sorted_arr[i]] = i;
        }
        int segments = n;
        int i=0;
        while(i<n){
            int sorted_idx = ele_idx[arr[i]];
            sorted_idx += 1; //1
            int i1 = i+1; //2
            while(sorted_idx < n && i1<n){
                if(sorted_arr[sorted_idx] == arr[i1]){
                    segments -= 1;
                    i1+=1;
                    sorted_idx += 1;
                    if(segments <= k) break;
                } else break;
            }
            if(segments <= k) break;
            i = i1; // 1
        }
        if(segments <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}