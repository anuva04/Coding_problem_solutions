// https://www.codechef.com/problems/RIFFLES

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> nextPos;

void decompose(int src, vector<bool>& visited, vector<int>& cycle){
    if(visited[src]) return;
    cycle.push_back(src);
    visited[src] = true;
    decompose(nextPos[src], visited, cycle);
}

void solve(){
    int n, k;
    cin>>n>>k;
    nextPos.resize(n+1);
    int num = 1;
    for(int i=1; i<=n-1; i+=2) nextPos[i] = num++;
    for(int i=2; i<=n; i+=2) nextPos[i] = num++;
    vector<bool> visited(n+1, false);
    vector<int> ans(n+1);
    for(int i=1; i<=n; i++){
        if(!visited[i]) {
        vector<int> cycle;
        decompose(i, visited, cycle);
        int len = cycle.size();
        for(int j=0; j<len; j++){
            ans[cycle[(j+k)%len]] = cycle[j];
        }}
    }
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << "\n";
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}