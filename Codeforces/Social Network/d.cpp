// https://codeforces.com/contest/1609/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

struct DSU {
    vector<int> parent, rank, sz;
    int connected_components;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        sz.resize(n+1, 1);
        connected_components = n;
        // for(int i=1; i<=n; i++) parent[i] = i;
        iota(parent.begin(), parent.end(), 0);
    }
    int getParent(int i){
        return ((parent[i] == i) ? i : (parent[i] = getParent(parent[i])));
    }
    int getComponentSize(int i){
        return sz[getParent(i)];
    }
    int getNumComponents(){
        return connected_components;
    }
    void unionComponents(int i, int j){
        if((i = getParent(i)) == (j = getParent(j))) return;
        else connected_components -= 1;
        if(rank[i] > rank[j]) swap(i, j);
        parent[i] = j;
        sz[j] += sz[i];
        if(rank[i] == rank[j]) rank[j] += 1;
        return;
    }
};

void solve(){
    int n, d, u, v;
    cin>>n>>d;

    DSU dsu(n);

    int extraEdges = 0;

    while(d--){
        cin>>u>>v;
        if(dsu.getParent(u) == dsu.getParent(v)) extraEdges++;
        else dsu.unionComponents(u,v);

        vector<bool> visited(n+1, false);
        vector<int> componentsSize;

        for(int node = 1; node<=n; node++){
            if(visited[dsu.getParent(node)]) continue;
            componentsSize.push_back(dsu.getComponentSize(node));
            visited[dsu.getParent(node)] = true;
        }

        sort(componentsSize.begin(), componentsSize.end());

        int ans = 0;
        int mergeableComponentsWithExtraEdges = extraEdges + 1;
        for(int i=(int)componentsSize.size()-1; i>=0 && mergeableComponentsWithExtraEdges>0; i--, mergeableComponentsWithExtraEdges--){
            ans += componentsSize[i];
        }

        // all the node in the same component could have been in the form of a star
        // the centre element would have most acquaintances
        // maximum acquaintances would be (size of component) - 1, if it a star-shaped component
        cout << ans-1 << endl;
    }
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}