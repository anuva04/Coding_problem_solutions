// https://codeforces.com/problemset/problem/1535/C

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
        string s; cin>>s;
        ll n = s.size();
        vector<pair<ll, ll>> non_b_range;
        ll i=0;
        while(i<n){
            ll j = i;
            if(i+1<n && s[i]!='?'){
                if(s[i]==s[i+1]) non_b_range.push_back({i,i+1});
                i++;
                continue;
            } else if (i+1 == n){
                i++;
                continue;
            }
            while(j<n && s[j]=='?') j++;
            if(i-1<0 || j==n) {
                i=j;
                continue;
            }
            ll left = i-1, right = j;
            ll length = j - i;
            if(length&1){
                if(s[left] != s[right]) non_b_range.push_back({left, right});
            } else {
                if(s[left] == s[right]) non_b_range.push_back({left, right});
            }
            i = j;
        }
        sort(non_b_range.begin(), non_b_range.end());
        ll ans = 0;
        ll st = 0;
        for(auto range : non_b_range){
            ans -= ((range.second - range.first - 1)*(range.second - range.first))/2;
            ans += ((range.second-st)*(range.second-st+1))/2;
            st = range.first + 1;
        }
        ans += ((n-st)*(n-st+1))/2;
        cout << ans << endl;
    }

    return 0;
}