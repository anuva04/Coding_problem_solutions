// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=499

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

struct Edge {
    int a, b, cost;
};

void solve(){
    int n, m; cin>>n>>m;
    vector<Edge> edges;
    int a, b, c;
    while(m--){
        cin>>a>>b>>c; 
        Edge e;
        e.a = a;
        e.b = b; 
        e.cost = c; 
        edges.push_back(e);
    }
    vector<int> d(n, INF);
    d[0] = 0;
    int x = 0;
    for(int i=0; i<n; i++){
        x = -1;
        for(auto e : edges){
            if(d[e.a] + e.cost < d[e.b]){
                d[e.b] = e.cost + d[e.a];
                x = e.b;
            }
        }
    }
    if(x == -1) cout << "not possible" << endl;
    else cout << "possible" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--) solve();

    // for(ll t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
        // solve();
    // }
    
    return 0;
}