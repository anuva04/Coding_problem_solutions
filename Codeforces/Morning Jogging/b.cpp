// https://codeforces.com/problemset/problem/1517/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        int n,m; cin>>n>>m;
        multiset<pair<int,int>> length_checkpoint;
        int ans[n][m];
        memset(ans, -1, sizeof ans);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x; cin>>x;
                length_checkpoint.insert({x,i});
            }
        }
        for(int i=0; i<m; i++){
            auto it = length_checkpoint.begin();
            ans[it->second][i] = it->first;
            length_checkpoint.erase(it);
        }
        while(!length_checkpoint.empty()){
            auto it = length_checkpoint.begin();
            int path=0;
            while(ans[it->second][path] != -1) path+=1;
            ans[it->second][path] = it->first;
            length_checkpoint.erase(it);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}