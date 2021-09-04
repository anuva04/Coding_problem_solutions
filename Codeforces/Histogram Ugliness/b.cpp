// https://codeforces.com/problemset/problem/1534/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        ll n; cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++) cin>>arr[i];
        ll original_height = 0;
        for(ll i=0; i<n; i++){
            ll left_height = 0;
            if(i-1>=0) left_height = arr[i-1];
            ll right_height = 0;
            if(i+1<n) right_height = arr[i+1];
            if(left_height < arr[i]) original_height += (arr[i]-left_height);
            if(right_height < arr[i]) original_height += (arr[i] - right_height);
            if((left_height<arr[i]) && (right_height<arr[i])){
                original_height -= (arr[i] - max(left_height, right_height));
            }
        }
        cout << original_height << endl;
    }
    return 0;
}