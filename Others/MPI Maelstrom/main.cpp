// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=364

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct edge {
    int u, v, cost;
};

void solve(){
    int n; cin>>n;
    vector<edge> edges;
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            string v; cin>>v;
            if(v == "x") continue;
            int c = stoi(v);
            edge e;
            e.u = j, e.v = i, e.cost = c;
            edges.push_back(e);
            e.u = i, e.v = j;
            edges.push_back(e);
        }
    }
    vector<int> dist(n+1, INF);
    dist[0] = dist[1] = 0;
    int m = edges.size();
    for(;;){
        bool relaxed = false;
        for(int j=0; j<m; j++){
            if(dist[edges[j].u] < INF){
                if(dist[edges[j].v] > dist[edges[j].u] + edges[j].cost){
                    dist[edges[j].v] = dist[edges[j].u] + edges[j].cost;
                    relaxed = true;
                }
            }
        }
        if(!relaxed) break;
    }
    int ans = *max_element(dist.begin(), dist.end());
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}