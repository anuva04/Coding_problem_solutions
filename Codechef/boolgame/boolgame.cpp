// https://www.codechef.com/APRIL21B/problems/BOOLGAME

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<ll> g(n);
        for(ll i=0; i<n; i++){
            cin>>g[i];
        }
        vector<vector<ll>> uvd(m);
        for(ll i=0; i<m; i++){
            ll u, v, d;
            cin>>u>>v>>d;
            uvd[i].push_back(u);
            uvd[i].push_back(v);
            uvd[i].push_back(d);
        }
        ll scores[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scores[i][j] = 0LL;
            }
        }
        for(ll i=0; i<n; i++) scores[i][i] = g[i];
        for(ll i=0; i<m; i++) scores[uvd[i][0]-1][uvd[i][1]-1] = uvd[i][2];

        ll score_update[n][n];
        for(ll i=0; i<n; i++) score_update[i][i] = scores[i][i];
        for(ll i=0; i<n-1; i++) score_update[i][i+1] = scores[i][i] + scores[i][i+1] + scores[i+1][i+1];
        for(ll len=2; len<n; len++){
            for(ll i=0; i<n-len; i++){
                score_update[i][i+len] = scores[i][i+len] + score_update[i+1][i+len] + score_update[i][i+len-1] - score_update[i+1][i+len-1];
            }
        }
        vector<ll> dp[n+1];
        dp[0].push_back(0LL);
        for(int i=0; i<n; i++){
            dp[i+1] = dp[i];
            for(int j=0; j<=i; j++){
                for(auto it : dp[max(j-1,0)]){
                    dp[i+1].push_back(score_update[j][i]+it);
                }
                sort(dp[i+1].begin(), dp[i+1].end(), [](ll a, ll b)->bool{return a>b;});
                while((int)dp[i+1].size()>k) dp[i+1].pop_back();
            }
        }
        for(ll ele : dp[n]) cout << ele << " ";
        cout << endl;
    }

    return 0;
}