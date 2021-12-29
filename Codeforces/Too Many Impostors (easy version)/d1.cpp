// https://codeforces.com/contest/1617/problem/D1

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void query(int x, int y, int z){
    cout << "? " << x << " " << y << " " << z << endl;
}

void solve(){
    int n; cin>>n;
    vector<int> adj(n);
    for(int i=0; i<n; i++){
        query(i+1, (i+1)%n + 1, (i+2)%n + 1);
        cin >> adj[i];
    }
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(adj[i] == adj[(i+1)%n]) continue;
        if(adj[i] == 0) ans.push_back(i+1);
        else ans.push_back((i+3)%n + 1);
        for(int j=0; j<n; j++){
            if(j==i || j==(i+3)%n) continue;
            query(i+1, (i+3)%n + 1, j+1);
            int response;
            cin>>response;
            if(response == 0) ans.push_back(j+1);
        }
        break;
    }
    cout << "! " << ans.size();
    for(auto& idx : ans) cout << " " << idx;
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
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