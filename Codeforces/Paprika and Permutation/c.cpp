// https://codeforces.com/contest/1617/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    set<int> to_be_made;
    for(int i=1; i<=n; i++) to_be_made.insert(i);
    vector<int> extras;
    for(int i=1; i<=n; i++){
        int num; cin>>num;
        if(to_be_made.count(num)) to_be_made.erase(num);
        else extras.push_back(num);
    }
    sort(extras.begin(), extras.end());
    reverse(extras.begin(), extras.end());
    for(auto& ex : extras){
        auto it = to_be_made.end();
        it--;
        int num = *it;
        if(num > (ex-1)/2){
            cout << -1 << endl;
            return;
        }
        to_be_made.erase(it);
    }
    cout << extras.size() << endl;
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
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}