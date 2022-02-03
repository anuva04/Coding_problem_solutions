// https://acm.timus.ru/problem.aspx?space=1&num=1671

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int num_sets;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        num_sets = n;
    }

    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
            num_sets -= 1;
        }
    }
};

void solve(){
    int n, m;
    cin>>n>>m;
    DSU dsu(n);
    map<int, pair<int,int>> id_edge;
    int a, b;
    for(int i=1; i<=m; i++){
        cin>>a>>b;
        id_edge[i] = {a, b};
    }
    vector<int> to_remove;
    set<int> remove;
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int id; cin>>id;
        to_remove.push_back(id);
        remove.insert(id);
    }

    for(auto ele : id_edge){
        int key = ele.first;
        int a = ele.second.first;
        int b = ele.second.second;
        if(remove.find(key) != remove.end()) continue;
        dsu.union_sets(a, b);
    }
    vector<int> ans;
    ans.push_back(dsu.num_sets);
    for(int i=q-1; i>=0; i--){
        int id = to_remove[i];
        int a = id_edge[id].first;
        int b = id_edge[id].second;
        dsu.union_sets(a, b);
        ans.push_back(dsu.num_sets);
    }
    ans.pop_back();
    for(int i=ans.size()-1; i>=0; i--) cout << ans[i] << ' '; cout << endl;
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