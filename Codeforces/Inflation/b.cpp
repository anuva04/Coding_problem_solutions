// https://codeforces.com/problemset/problem/1476/B

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
        int n;
        ld k;
        cin>>n>>k;
        ld arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        ld old_sum = 0.0, new_sum = 0.0;
        for(int i=1; i<n; i++){
            old_sum += arr[i-1];
            new_sum += arr[i-1];
            if(arr[i]/new_sum*(1.0*100) > k){
                ld diff = (arr[i]*(1.0*100))/k - new_sum;
                diff = ceil(diff);
                new_sum += diff;
            }
        }
        cout << (ll)(new_sum - old_sum) << endl;
    }
    
    return 0;
}