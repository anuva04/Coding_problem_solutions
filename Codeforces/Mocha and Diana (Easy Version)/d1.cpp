// https://codeforces.com/problemset/problem/1559/D1

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int n, m1, m2;
int dsu[2][2005];

int getParent(int id, int x){
    return x == dsu[id][x] ? x : dsu[id][x] = getParent(id, dsu[id][x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // ll test; cin>>test;
    // while(test--){
        cin>>n>>m1>>m2;
        for(int i=1; i<=n; i++) dsu[0][i] = dsu[1][i] = i;
        for(int i=1; i<=m1; i++){
            int u, v;
            cin>>u>>v;
            int u_parent = getParent(0, u);
            int v_parent = getParent(0, v);
            dsu[0][u_parent] = v_parent;
        }
        for(int i=1; i<=m2; i++){
            int u, v;
            cin>>u>>v;
            int u_parent = getParent(1, u);
            int v_parent = getParent(1, v);
            dsu[1][u_parent] = v_parent;
        }
        vector<pair<int,int>> ans;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(getParent(0,i) != getParent(0, j) && getParent(1,i) != getParent(1,j)){
                    ans.push_back({i,j});
                    dsu[0][getParent(0,i)] = getParent(0,j);
                    dsu[1][getParent(1,i)] = getParent(1,j);
                }
            }
        }
        cout << ans.size() << endl;
        for(auto ele : ans) cout << ele.first << " " << ele.second << endl;
    // }
    return 0;
}