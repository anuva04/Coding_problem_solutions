// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1140

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> disc, low;
int timer;
unordered_set<int> articulation_points;

void dfs(int v, int p = -1){
    visited[v] = true;
    disc[v] = low[v] = timer++;
    int children = 0;
    for(int to : adj[v]){
        if(to == p) continue;
        if(visited[to]) low[v] = min(low[v], disc[to]);
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] >= disc[v] && p != -1) articulation_points.insert(v);
            ++children;
        }
    }
    if(p == -1 && children > 1) articulation_points.insert(v);
}

void find_articulation_points(int n){
    timer = 0;
    articulation_points.clear();
    visited.assign(n+1, false);
    disc.assign(n+1, -1);
    low.assign(n+1, -1);
    for(int i=1; i<=n; i++){
        if(!visited[i]) dfs(i);
    }

}

void solve(int n){
    map<string, int> cities;
    map<int, string> id_cities;
    string city;
    int id = 1;
    for(int i=0; i<n; i++){
        cin>>city;
        cities[city] = id;
        id_cities[id] = city;
        id++;
    }
    int m; cin>>m;
    adj.clear();
    adj.resize(n+1);
    string c1, c2;
    while(m--){
        cin>>c1>>c2;
        adj[cities[c1]].push_back(cities[c2]);
        adj[cities[c2]].push_back(cities[c1]);
    }
    find_articulation_points(n);
    cout << (int)articulation_points.size() << " camera(s) found" << endl;
    vector<string> city_names;
    for(int id : articulation_points) city_names.push_back(id_cities[id]);
    sort(city_names.begin(), city_names.end());
    for(string s : city_names) cout << s << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    int cnt = 1;
    while(cin>>n && n){
        if(cnt > 1) cout << endl;
        cout << "City map #" << cnt << ": ";
        solve(n);
        cnt++;
    }

    // ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}