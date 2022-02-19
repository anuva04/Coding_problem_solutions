// https://www.spoj.com/problems/LEGO/

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
    int n; cin>>n;
    DSU dsu(n);
    map<int, vector<pair<pii, int>>> ending_y, starting_y;
    map<int, vector<int>> id_lego;
    int x1, y1, x2, y2;
    for(int i=1; i<=n; i++){
        cin>>x1>>y1>>x2>>y2;
        id_lego[i] = {x1, y1, x2, y2};
        ending_y[y2].push_back({{x1, x2}, i});
        starting_y[y1].push_back({{x1, x2}, i});
    }
    for(auto ele : ending_y) sort(ele.second.begin(), ele.second.end());
    for(auto ele : starting_y) sort(ele.second.begin(), ele.second.end());
    for(auto layer : starting_y){
        int y = layer.first;
        if(!ending_y.count(y)) continue;
        int i = 0, j = 0; // i = up, j = down
        while(i < starting_y[y].size() && j < ending_y[y].size()){
            int up_x1 = starting_y[y][i].first.first;
            int up_x2 = starting_y[y][i].first.second;
            int down_x1 = ending_y[y][j].first.first;
            int down_x2 = ending_y[y][j].first.second;
            if(up_x2 <= down_x1) i++;
            else if(down_x2 <= up_x1) j++;
            else {
                dsu.merge(starting_y[y][i].second, ending_y[y][j].second);
                if(up_x2 < down_x2) i++;
                else if(down_x2 < up_x2) j++;
                else {i++; j++;}
            }
        }
    }
    cout << dsu.get_num_sets() << endl;
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
   for(ll t=1; t<=test; t++){
       cout << "Case " << t << ": ";
       solve();
   }
    
    return 0;
}