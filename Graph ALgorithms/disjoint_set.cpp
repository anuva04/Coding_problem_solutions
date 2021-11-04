#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> parent;
vector<int> rankSet;

void makeSet(int v){
    parent[v] = v;
    rankSet[v] = 1;
}

int findSet(int v){
    if(v == parent[v]) return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(rankSet[a] < rankSet[b]) swap(a,b);
        parent[b] = a;
        if(rankSet[a] == rankSet[b]) rankSet[a]++;
    }
}


int main(){
    parent.clear();
    rankSet.clear();
    int n; cin>>n;
    parent.resize(n);
    rankSet.resize(n);
    for(int i=0; i<n; i++){
        makeSet(i);
    }
    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type == 1){
            int find; cin>>find;
            cout << findSet(find) << endl;
        } else {
            int x, y; cin>>x>>y;
            unionSet(x,y);
        }
    }
}