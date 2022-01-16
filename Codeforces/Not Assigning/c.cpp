// https://codeforces.com/contest/1627/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
	map<pair<int,int>, int> edge_num;
	bool is = true;
	vector<vector<int>> adj(n+1);
	for(int i=1; i<=n-1; i++){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if((int)adj[u].size()>2 || (int)adj[v].size()>2) is = false; 
		edge_num[{min(u,v),max(u,v)}] = i;
	}
	if(!is) cout << -1 << endl;
	else {
		vector<int> edge(n);
		int src = -1;
		for(int i=1; i<=n; i++){
			if((int)adj[i].size()==1) {
				src = i;
				break;
			}
		}

		int edges = n-1;
		int val = 2;
		int par = src;
		src = adj[src][0];
		while(edges--){
			edge[edge_num[{min(par, src), max(par, src)}]] = val;
			if(val == 2) val = 5;
			else val = 2;
			int prev = src;
			if(adj[src][0]!= par) src = adj[src][0];
			else src = adj[src][1];
			par = prev;
		}
		for(int i=1; i<=n-1; i++) cout << edge[i] << ' ';
		cout << endl;
	}
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}