// https://codeforces.com/problemset/problem/1579/D

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
        multiset<pair<int,int>> s;
        for(int i=1; i<=n; i++){
            int x; cin>>x;
            if(x>0) s.insert({x,i});
        }
        vector<pair<int,int>> res;
        while(s.size()>1){
            pair<int,int> first = *s.begin();
            pair<int,int> second = *s.rbegin();
            res.push_back({first.second, second.second});
            s.erase(s.begin());
            auto it = prev(s.end());
            s.erase(it);
            first.first -= 1;
            if(first.first>0) s.insert({first.first, first.second});
            second.first -= 1;
            if(second.first > 0) s.insert({second.first, second.second});
        }
        cout << res.size() << endl;
        for(auto ele : res){
            cout << ele.first << " " << ele.second << endl;
        }
    }
    
    return 0;
}