// https://www.spoj.com/problems/CTRICK/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct BIT {
    vector<int> bit;
    int n;

    BIT(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    BIT(vector<int> a)
        : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int binary_search(int l, int r, int start, int key, BIT& b){
    while(1){
        if(l == r) return l;
        if(r-l == 1){
            int blanks = b.sum(start, l);
            if(blanks >= key) return l;
            return r;
        } else {
            int m = (l+r)>>1;
            int blanks = b.sum(start, m);
            if(blanks >= key) r = m;
            else l = m+1;
        }
    }
}

void solve(){
    int n; cin>>n;
    if(n==1){
        cout << 1 << endl;
        return;
    }
    vector<int> ans(n, -1);
    vector<int> arr(n, 1);
    BIT b(arr);
    ans[1] = 1;
    b.add(1, -1);
    arr[1] = 0;
    int prev_idx = 1;
    for(int i=2; i<=n; i++){
        // for(auto ele : b.bit) cout << ele << ' '; cout << endl;
        // for(auto ele : arr) cout << ele << ' '; cout << endl;
        int gap = i;
        int left_blanks = 0, right_blanks = 0;
        if(prev_idx>0) left_blanks = b.sum(0, prev_idx-1);
        if(prev_idx<n-1) right_blanks = b.sum(prev_idx+1, n-1);
        // cout << left_blanks << ' ' << right_blanks << endl;
        gap %= (left_blanks + right_blanks);
        int idx = -1;
        if(gap < right_blanks){
            idx = binary_search(prev_idx+1, n-1, prev_idx+1, gap+1, b);
        } else {
            gap -= right_blanks;
            idx = binary_search(0, prev_idx-1, 0, gap+1, b);
        }
        // cout << idx << endl;
        ans[idx] = i;
        b.add(idx, -1);
        arr[idx] = 0;
        prev_idx = idx;
    }
    for(auto ele : ans) cout << ele << ' ';
    cout << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}