// https://codeforces.com/problemset/problem/1548/A

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

    int n,m; cin>>n>>m;
    vector<int> stronger(n,0);
    int surviving_nobles  = n;
    while(m--){
        int u,v; cin>>u>>v;
        if(u>v) swap(u,v);
        u--; v--;
        if(stronger[u] == 0) surviving_nobles -= 1;
        stronger[u] += 1;
    }
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==3){
            cout << surviving_nobles << endl;
        } else {
            int u, v; cin>>u>>v;
            if(type == 1){
                if(u>v) swap(u,v);
                u--; v--;
                if(stronger[u] == 0) surviving_nobles -= 1;
                stronger[u] += 1;
            } else if(type == 2){
                if(u>v) swap(u,v);
                u--; v--;
                stronger[u]--;
                if(stronger[u] == 0) surviving_nobles+=1;
            }
        }
    }

    return 0;
}