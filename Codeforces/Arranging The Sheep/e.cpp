// https://codeforces.com/problemset/problem/1520/E

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
        string s; cin>>s;
        int sheep_cnt = 0;
        for(auto pos : s){
            sheep_cnt += (pos=='*')?1:0;
        }
        int mid_sheep_num = sheep_cnt/2;
        int mid_sheep_pos = -1;
        int cur_sheep_cnt = -1;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                cur_sheep_cnt += 1;
                if(cur_sheep_cnt == mid_sheep_num) mid_sheep_pos = i;
            }
        }
        ll ans = 0;
        int final_sheep_pos = mid_sheep_pos - mid_sheep_num;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                ans += abs(i - final_sheep_pos);
                final_sheep_pos += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}