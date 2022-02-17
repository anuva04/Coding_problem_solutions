// https://codeforces.com/contest/1638/problem/C

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
    int n; cin>>n;
    DSU dsu(n);
    vector<int> a(n);
    set<int> s;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        if(!s.empty()){
            auto it = s.lower_bound(a[i]);
            // cout << *it << "::" << endl;
            if(it != s.end()) {
                vector<int> rem;
                for(auto t = it; t != s.end(); t++) {
                    rem.push_back(*t);
                    dsu.union_sets(a[i], *t);
                }
                // for(int i=0; i<rem.size(); i++) {
                //     cout << rem[i] << ' ';
                // }
                // cout << endl;
                for(int i=0; i<rem.size()-1; i++) {
                    s.erase(rem[i]);
                }
            } else {
                s.insert(a[i]);
            }
        } else {
            // cout << a[i] << ":::" << endl;
            s.insert(a[i]);
        }
    }
    cout << dsu.num_sets << endl;
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
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}