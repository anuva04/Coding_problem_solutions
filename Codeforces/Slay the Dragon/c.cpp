// https://codeforces.com/contest/1574/problem/C

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

    ll n; cin>>n;
    ll total_strength = 0;
    set<ll> heros;
    for(ll i=0; i<n; i++){
        ll x; cin>>x;
        total_strength += x;
        heros.insert(x);
    }
    ll m; cin>>m;
    vector<ll> defense(m);
    vector<ll> attack(m);
    for(ll i=0; i<m; i++){
        cin>>defense[i];
        cin>>attack[i];
    }
    vector<ll> ans;
    for(ll i=0; i<m; i++){
        ll coins = 0;
        ll def = defense[i];
        ll att = attack[i];
        auto it = heros.lower_bound(def);
        if(it == heros.begin()){
            ll rem_hero_def = total_strength - *it;
            if(att > rem_hero_def) coins += (att - rem_hero_def);
        } else if(it != heros.end()){
            ll cand1 = 0, cand2 = 0;

            if(*it < def) cand1 += (def - *it);
            ll rem_hero_def = total_strength - *it;
            if(att > rem_hero_def) cand1 += (att - rem_hero_def);

            auto new_it = it; new_it--;
            if(*new_it < def) cand2 += (def - *new_it);
            rem_hero_def = total_strength - *new_it;
            if(att > rem_hero_def) cand2 += (att - rem_hero_def);

            coins += min(cand1, cand2);
        } else {
            ll cand1 = 0;
            auto new_it = it; new_it--;
            if(*new_it < def) cand1 += (def - *new_it);
            ll rem_hero_def = total_strength - *new_it;
            if(att > rem_hero_def) cand1 += (att - rem_hero_def);
            coins += cand1;
        }
        ans.push_back(coins);
    }
    for(auto ele : ans) cout << ele << endl;

    return 0;
}