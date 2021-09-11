// https://codeforces.com/problemset/problem/1539/C

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
    ll n, additional_students, allowed_diff;
    cin>>n>>additional_students>>allowed_diff;
    vector<ll> arr(n);
    for(ll i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    vector<ll> gaps;
    for(ll i=1; i<n; i++){
        if(arr[i]-arr[i-1]>allowed_diff) gaps.push_back(arr[i]-arr[i-1]);
    }
    sort(gaps.begin(), gaps.end());
    ll stable = gaps.size()+1;
    for(ll i=0; i<gaps.size(); i++){
        ll needed_students = gaps[i]/allowed_diff;
        if(gaps[i]%allowed_diff == 0) needed_students-=1;
        if(additional_students>=needed_students){
            additional_students -= needed_students;
            stable -= 1;
        }
    }
    cout << stable << endl;

    return 0;
}