// https://codeforces.com/contest/1631/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n+1);
    vector<int> freq(n+1, 0); // freq[i] will store number of occurences of element i
    int num;
    for(int i=1; i<=n; i++){
        cin>>num;
        a[i] = num;
        freq[num]++;
    }

    vector<int> pre(n+1, 0); // pre[i] will store number of elements less than or equal to i
    for(int i=1; i<=n; i++) pre[i] = pre[i-1] + freq[i];

    // our final range will be [x, y] and we want to minimise len = (y-x)
    // so binary search over len = 0 to len = n
    int min_len = 0, max_len = n;
    while(max_len > min_len + 1){
        int mid_len = (min_len + max_len)/2;
        bool possible = false;
        for(int i=1; i<=n-mid_len+1; i++){
            int num_elements_in_range = pre[i+mid_len-1] - pre[i-1];
            int num_elements_out_of_range = n - num_elements_in_range;
            if(num_elements_in_range - num_elements_out_of_range >= k) {
                possible = true;
                break;
            }
        }
        if(possible) max_len = mid_len;
        else min_len = mid_len;
    }

    // cout << max_len << endl;

    // max_len is the minimum possible range length
    // for this length, find [x, y] such that y - x = max_len
    int x, y;
    for(int i=1; i<=n-max_len+1; i++){
        int num_elements_in_range = pre[i + max_len - 1] - pre[i-1];
        int num_elements_out_of_range = n - num_elements_in_range;
        if(num_elements_in_range - num_elements_out_of_range >= k){
            x = i;
            y = i + max_len - 1;
            // break;
        }
    }

    cout << x << ' ' << y << endl;
    pre.assign(n+1, 0);
    for(int i=1; i<=n; i++) pre[i] = (a[i]>=x && a[i]<=y) ? 1 : -1;
    // for(auto ele : pre) cout << ele << ' '; cout << endl;
    int start = 1;
    int sum = 0;
    
    if(k==1) {
        cout << start << ' ' << n << endl;
        return;
    }
    for(int i=1; i<=n-1; i++){
        sum += pre[i];
        if(sum >= 1){
            cout << start << ' ' << i << endl;
            start = i+1;
            k -= 1;
            sum = 0;
        }
        if(k == 1) break;
    }
    cout << start << ' ' << n << endl;
    // cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}