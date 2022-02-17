// https://www.spoj.com/problems/CONGRAPH/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    int num_sets;

public:
    DSU(int n){
        parent.resize(n+1);
        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }
        rank.assign(n+1, 1);
        num_sets = n;
    }
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
            num_sets--;
        }
    }
    int get_num_sets(){
        return num_sets;
    }
};

void solve(){
    int n, m;
    cin>>n>>m;
    int a, b;
    DSU dsu(n);
    while(m--){
        cin>>a>>b;
        dsu.merge(a, b);
    }
    int roads = dsu.get_num_sets() - 1;
    cout << roads << endl;
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