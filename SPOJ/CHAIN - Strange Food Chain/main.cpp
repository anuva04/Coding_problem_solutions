// https://www.spoj.com/problems/CHAIN/
// https://www.quora.com/How-do-I-solve-the-strange-food-chain-question-on-SPOJ

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
    vector<int> relation_with_root; // 0 -> same type, 1 -> node eats root, 2 -> root eats node
    int cnt_false, n;

    DSU(int _n){
        n = _n;
        parent.resize(n);
        relation_with_root.resize(n);
        for(int i=0; i<n; i++) {
            parent[i] = i;
            relation_with_root[i] = 0;
        }
        cnt_false = 0;
    }

    int find_set(int v){
        if(v == parent[v]) return v;
        int par = parent[v];
        parent[v] = find_set(parent[v]);
        relation_with_root[v] += relation_with_root[par];
        return parent[v];
    }

    void union_sets(int a, int b, int type){
        if(a >= n || b >= n){
            cnt_false++;
            return;
        }

        int pa = find_set(a);
        int pb = find_set(b);

        int new_relation = ((relation_with_root[a] - relation_with_root[b] - type)%3 + 3)%3;

        if(pa == pb){
            if(new_relation != 0) cnt_false++;
        } else {
            parent[pa] = pb;
            relation_with_root[pa] = 3 - new_relation;
        }
    }
};

void solve(){
    int n, k; cin>>n>>k;
    DSU dsu(n);
    int type, a, b;
    while(k--){
        cin>>type>>a>>b;
        dsu.union_sets(a-1, b-1, type-1);
    }
    cout << dsu.cnt_false << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int test; cin>>test;
    while(test--){
        solve();
    }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}