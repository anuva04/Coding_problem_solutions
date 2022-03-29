// https://codingcompetitions.withgoogle.com/codejamio/round/00000000009d9870/0000000000a33bc7
// partial solution

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const ll INF = 1e18;

void solve(){
    int n; cin>>n;
    vector<vector<ll>> adj(n+1, vector<ll>(n+1, INF));
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    int a, b, c;
    for(int i=0; i<n-1; i++){
        cin>>a>>b>>c;
        adj[a][b] = c;
        adj[b][a] = c; 
        dist[a][b] = c;
        dist[b][a] = c;
    }
    for(int k=1; k<=n; k++){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(dist[i][k] < INF && dist[k][j] < INF){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    ll cost = INF;
    vector<int> cities;
    for(int i=1; i<=n; i++) cities.push_back(i);
    do {
        ll curr = 0;
        for(int i=1; i<n; i++){
            curr += dist[cities[i-1]][cities[i]];
        }
        cost = min(cost, curr);
    } while(next_permutation(cities.begin(), cities.end()));
    cout << cost << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int test; cin>>test;

    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}