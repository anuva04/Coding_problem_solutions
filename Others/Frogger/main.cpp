// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=475

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
    float cost;
};

float dist(int x1, int y1, int x2, int y2){
    float ans = sqrt((1.0*x1 - 1.0*x2)*(1.0*x1 - 1.0*x2) + (1.0*y1 - 1.0*y2)*(1.0*y1 - 1.0*y2));
    return ans;
}

void solve(int n){
    vector<edge> edges;
    vector<pair<int,int>> coords;
    for(int i=0; i<n; i++){
        int x, y; cin>>x>>y;
        coords.push_back({x,y});
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            float c = dist(coords[i].first, coords[i].second, coords[j].first, coords[j].second);
            edge e;
            e.u = i, e.v = j, e.cost = c;
            edges.push_back(e);
        }
    }
    vector<float> dist(n+1, INF);
    dist[0] = 0;
    int m = edges.size();
    for(;;){
        bool relaxed = false;
        for(int j=0; j<m; j++){
            if(dist[edges[j].u] < INF){
                if(dist[edges[j].v] > max(dist[edges[j].u], edges[j].cost)){
                    dist[edges[j].v] = max(dist[edges[j].u], edges[j].cost);
                    relaxed = true;
                }
            }
        }
        if(!relaxed) break;
    }
    cout << fixed << setprecision(3) << dist[1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int i = 1;
    while(i++){
        int n; cin>>n;
        if(n == 0) {break;}
        cout << "Scenario #" << i-1 << endl;
        cout << "Frog Distance = ";
        solve(n);
        cout << endl;
    }
    
    return 0;
}