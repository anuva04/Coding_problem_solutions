// https://codeforces.com/problemset/problem/510/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

vector<vector<int>> adj;
vector<int> ans, color;

void dfs(int v){
    color[v] = 1;

    for(int u : adj[v]){
        if(color[u] == 1) return;
        else if(color[u] == 0) dfs(u);
    }
    color[v] = 2;
    ans.push_back(v);
}

void topological_sort(){
    color.assign(26, 0);
    ans.clear();
    for(int i=0; i<26; i++){
        if(color[i] == 0) dfs(i);
    }
}

void solve(){
    adj.clear(); adj.resize(26);
    int n; cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            int s1 = 0, s2 = 0;
            bool ok = false;
            while(s1 < v[j].size() && s2 < v[i].size()){
                if(v[j][s1] == v[i][s2]) s1++, s2++;
                else {
                    adj[v[i][s2]-'a'].push_back(v[j][s1]-'a');
                    ok = true;
                    break;
                }
            }
            if(!ok){
                if((int)v[i].size() < (int)v[j].size()) {
                    cout << "Impossible" << endl;
                    return;
                }
            }
        }
    }
    topological_sort();
    if((int)ans.size() < 26) {
        cout << "Impossible" << endl;
        return;
    }
    string ret = "";
    for(int i : ans){
        ret += (char)('a' + i);
    }
    cout << ret << endl;
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
    //     cout << "Caso #" << t << endl;
    //     solve();
    // }
    
    return 0;
}