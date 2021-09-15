// https://codeforces.com/problemset/problem/1530/C

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
        int n; cin>>n;
        vector<int> a, b;
        int a_score = 0, b_score = 0;
        for(int i=0; i<n; i++) {
            int x; cin>>x;
            a.push_back(x);
            a_score += x;
        }
        for(int i=0; i<n; i++) {
            int x; cin>>x;
            b.push_back(x);
            b_score += x;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = n/4;
        for(int i=0; i<k; i++){
            a_score -= a[i];
            b_score -= b[i];
        }
        if(a_score >= b_score){
            cout << 0 << endl;
            continue;
        }
        int a_idx = k, b_idx = k-1;
        int rounds = n;
        int ans = 0;
        int zeros_in_b = 0;
        while(true){
            if(a_score >= b_score) break;
            a_score += 100;
            zeros_in_b += 1;
            if(b_idx >= 0){
                b_score += b[b_idx];
                b_idx -= 1;
            }
            rounds += 1;
            if(rounds/4 > k){
                k += 1;
                a_score -= a[a_idx];
                a_idx += 1;
                if(zeros_in_b < k){
                    b_score -= b[b_idx+1];
                    b_idx += 1;
                }
            }
            ans += 1;
        }
        cout << ans << endl;
    }

    return 0;
}