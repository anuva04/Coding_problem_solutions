// https://codeforces.com/problemset/problem/1519/C

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
        ll n; cin>>n;
        vector<ll> u(n+1);
        for(ll i=1; i<=n; i++) cin>>u[i];
        vector<ll> s(n+1);
        for(ll i=1; i<=n; i++) cin>>s[i];

        map<ll, vector<ll>> uni_studs;
        for(ll i=1; i<=n; i++){
            uni_studs[u[i]].push_back(s[i]);
        }

        for(auto& studs : uni_studs){
            auto& skills = studs.second;
            sort(skills.begin(), skills.end(), greater<ll>());
            for(ll i=1; i<skills.size(); i++){
                skills[i] += skills[i-1];
            }
        }

        // for(auto& studs : uni_studs){
        //     auto& uni = studs.first;
        //     auto& skills = studs.second;
        //     cout << uni << ": ";
        //     for(auto ele : skills) cout << ele << ' ';
        //     cout << endl;
        // }

        // for(ll k=1; k<=n; k++){
        //     ll ans = 0;
        //     for(auto studs : uni_studs){
        //         auto skills = studs.second;
        //         ll sz = skills.size();
        //         ll pos_idx = sz - (sz%k);
        //         if(pos_idx-1 >=0) ans += skills[pos_idx-1];
        //     }
        //     cout << ans << " ";
        // }

        vector<ll> ans(n,0);

        for(auto studs : uni_studs){
            auto skills = studs.second;
            ll sz = skills.size();
            for(ll k=1; k<=sz; k++){
                ll pos_idx = sz - (sz%k);
                ll skill = skills[pos_idx-1];
                ans[k-1] += skill;
            }
        }

        for(ll i=0; i<n; i++) cout << ans[i] << " ";

        cout << endl;
    }
    
    return 0;
}