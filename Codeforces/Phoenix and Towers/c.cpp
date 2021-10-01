// https://codeforces.com/problemset/problem/1515/C

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
        int n,m,x;
        cin>>n>>m>>x;
        set<pair<int,int>> s;
        for(int i=1; i<=m; i++){
            s.insert({0,i});
        }
        cout << "YES" << endl;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            auto y = *s.begin();
            s.erase(s.begin());
            cout << y.second << " ";
            y.first += x;
            s.insert(y);
        }
        cout << endl;
    }
    
    return 0;
}