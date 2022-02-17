// https://www.spoj.com/problems/BOTTOM/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, component;
vector<vector<int>> components;

void dfs1(int v){
    used[v] = true;
    for(auto u : g[v]){
        if(!used[u]) dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v){
    used[v] = true;
    component.push_back(v);
    for(auto u : gt[v]){
        if(!used[u]) dfs2(u);
    }
}

void solve(int v){
    g.clear(); gt.clear(); used.clear(); order.clear(); component.clear(); components.clear();

    int e; cin>>e;
    int a, b;
    g.resize(v+1);
    gt.resize(v+1);
    while(e--){
        cin>>a>>b;
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    used.assign(v+1, false);
    for(int i=1; i<=v; i++) {
        if(!used[i]) dfs1(i);
    }

    used.assign(v+1, false);
    reverse(order.begin(), order.end());

    for(auto v : order){
        if(!used[v]){
            dfs2(v);
            components.push_back(component);
            component.clear();
        }
    }

    vector<int> ans;
    for(auto com : components){
        unordered_set<int> comp_set;
        for(auto v : com) comp_set.insert(v);
        bool ok = true;
        for(auto v : com){
            for(auto nei : g[v]){
                if(!comp_set.count(nei)){
                    ok = false;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok) {
            for(auto v : com) ans.push_back(v);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto ele : ans) cout << ele << ' ';
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    while(true){
        int v; cin>>v;
        if(v == 0) break;
        solve(v);
    }

    // ll test; cin>>test;
    // while(test--){
        // solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}