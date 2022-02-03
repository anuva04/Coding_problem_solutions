// https://codeforces.com/contest/25/problem/D

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

    bool union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(rank[a] < rank[b]) swap(a,b);
            parent[b] = a;
            if(rank[a] == rank[b]) rank[a]++;
            num_sets -= 1;
            return true;
        }
        return false;
    }
};

void solve(){
    int n; cin>>n;
    DSU dsu(n);
    vector<pair<int,int>> redundant;
    int a, b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        bool f = dsu.union_sets(a, b);
        if(!f) redundant.push_back({a,b});
    }
    int num_sets = dsu.num_sets;
    cout << num_sets-1 << endl;
    if(num_sets > 1){
        set<int> reps;
        for(int i=1; i<=n; i++){
            int rep = dsu.find_set(i);
            reps.insert(rep);
        }
        vector<int> representatives;
        for(auto ele : reps) representatives.push_back(ele);
        for(int i=1; i<representatives.size(); i++){
            int a = redundant[i-1].first;
            int b = redundant[i-1].second;
            int c = representatives[i-1];
            int d = representatives[i];
            cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
        }
    }
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