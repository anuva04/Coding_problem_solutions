// https://acm.timus.ru/problem.aspx?space=1&num=1930

// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

const int maxn = 10001;

vector<int> adj_list[maxn], adj_mat[maxn];
int dist[maxn][2];

int dijkstra(int src, int dest){
    memset(dist, -1, sizeof dist);
    dist[src][0] = 0;
    dist[src][1] = 0;
    priority_queue< pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>> > q;
    q.push({0, {src, 0}});
    q.push({0, {src, 1}});

    while(!q.empty()){
        auto top = q.top();
        q.pop();


        int d = top.first;
        int node = top.second.first;
        int dir = top.second.second;

        if(node == dest) return d;

        for(int i=adj_list[node].size()-1; i>=0; i--){
            int nei = adj_list[node][i];
            int new_dir = adj_mat[node][i];
            int new_d = d + ((new_dir == dir) ? 0 : 1);

            if(dist[nei][new_dir]==-1 || dist[nei][new_dir] > new_d){
                dist[nei][new_dir] = new_d;
                q.push({new_d, {nei, new_dir}});
            }
        }
    }
    return -1;
}

void solve(){
    int n, m; cin>>n>>m;

    int u, v;
    while(m--){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        adj_mat[u].push_back(1);
        adj_mat[v].push_back(0);
    }

    int src, dest; cin>>src>>dest;
    cout << dijkstra(src, dest) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}