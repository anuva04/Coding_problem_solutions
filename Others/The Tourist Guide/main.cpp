// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1040

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

struct edge {
    int u, v;
    int cost;
};

void solve(int n, int r){
    vector<edge> edges;
    for(int i=0; i<r; i++){
        int u, v, c; cin>>u>>v>>c;
        edge e;
        e.u = u, e.v = v, e.cost = c;
        edges.push_back(e);
        e.u = v, e.v = u;
        edges.push_back(e);
    }
    int s, d, passengers;
    cin>>s>>d>>passengers;
    vector<int> dist(n+1, -1);
    dist[s] = INT_MAX;
    int m = edges.size();
    for(;;){
        bool relaxed = false;
        for(int j=0; j<m; j++){
            if(dist[edges[j].u] > -1){
                if(dist[edges[j].v] < min(dist[edges[j].u], edges[j].cost)){
                    dist[edges[j].v] = min(dist[edges[j].u], edges[j].cost);
                    relaxed = true;
                }
            }
        }
        if(!relaxed) break;
    }
    int capacity = dist[d];
    int trips = (int)ceil((double)passengers/(capacity - 1.0));
    cout << trips << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int i = 1;
    while(i++){
        int n, r; cin>>n>>r;
        if(n == 0 && r==0) {break;}
        cout << "Scenario #" << i-1 << endl;
        cout << "Minimum Number of Trips = ";
        solve(n, r);
        cout << endl;
    }
    
    return 0;
}