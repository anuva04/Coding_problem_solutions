// https://codeforces.com/contest/1586/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

void solve(){
    int n, m; cin>>n>>m;
    vector<vector<int>> res(m, vector<int>(3));
    vector<bool> res_node(n+1, false);
    for(int i=0; i<m; i++){
        cin>>res[i][0]>>res[i][1]>>res[i][2];
        res_node[res[i][1]] = true;
        // cout << res_node[res[i][1]] << endl;
    }
    int not_res;
    for(int i=1; i<=n; i++){
        if(res_node[i] == false){ not_res = i; break;}
    }
    // cout << not_res << endl;
    for(int i=1; i<=n; i++){
        if(i==not_res) continue;
        cout << i << " " << not_res << endl;
    }
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
    
    return 0;
}