// https://codeforces.com/contest/1569/problem/D

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
        int n,m,k;
        cin>>n>>m>>k;
        set<int> x,y;
        while(n--){
            int xi; cin>>xi;
            x.insert(xi);
        }
        while(m--){
            int yi; cin>>yi;
            y.insert(yi);
        }
        map<int,int> between_same_hr, between_same_vr;
        map<pair<int,int>,int> same_hr_seg, same_vr_seg;
        while(k--){
            int xp, yp;
            cin>>xp>>yp;
            if(!x.count(xp)){
                auto just_greater_x = x.lower_bound(xp);
                between_same_vr[*just_greater_x]++;
                same_hr_seg[{*just_greater_x, yp}]++;
            } else if(!y.count(yp)){
                auto just_greater_y = y.lower_bound(yp);
                between_same_hr[*just_greater_y]++;
                same_vr_seg[{*just_greater_y, xp}]++;
            }
        }
        ll ans = 0;
        for(auto ele : between_same_hr) ans += ele.second*((ll)ele.second-1)/2;
        for(auto ele : same_vr_seg) ans -= ele.second*((ll)ele.second-1)/2;
        for(auto ele : between_same_vr) ans += ele.second*((ll)ele.second-1)/2;
        for(auto ele : same_hr_seg) ans -= ele.second*((ll)ele.second-1)/2;

        cout << ans << endl;
    }

    return 0;
}