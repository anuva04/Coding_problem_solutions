// https://codeforces.com/problemset/problem/1511/C

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


    // ll test; cin>>test;
    // while(test--){

    // }
    int n, q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> res;
    while(q--){
        int color; cin>>color;
        int i = 0;
        for(i=0; i<n; i++){
            if(arr[i] == color) break;
        }
        res.push_back(i+1);
        rotate(arr.begin(), arr.begin()+i, arr.begin()+i+1);
    }
    for(auto ele : res) cout << ele << " ";
    return 0;
}