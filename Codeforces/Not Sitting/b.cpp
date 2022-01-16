// https://codeforces.com/contest/1627/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> arr;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int mx = dist(0,0,i,j);
            mx = max(mx, dist(0,m-1,i,j));
            mx = max(mx, dist(n-1,0,i,j));
            mx = max(mx, dist(n-1,m-1,i,j));
            arr.push_back(mx);
        }
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<m*n; i++) cout << arr[i] << ' ';
    cout << endl;
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
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}