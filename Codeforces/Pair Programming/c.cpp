// https://codeforces.com/problemset/problem/1547/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int k, n, m;
        cin>>k>>n>>m;
        vector<int> nv(n);
        vector<int> mv(m);
        for(int i=0; i<n; i++) cin>>nv[i];
        for(int i=0; i<m; i++) cin>>mv[i];
        int ni=0, mi=0;
        vector<int> res;
        bool flag = true;
        while(ni<n && mi<m){
            if(nv[ni] <= mv[mi]){
                if(nv[ni]>k){
                    flag = false;
                    break;
                } else {
                    res.push_back(nv[ni]);
                    if(nv[ni]==0) k+=1;
                }
                ni += 1;
            } else {
                if(mv[mi]>k){
                    flag = false;
                    break;
                } else {
                    res.push_back(mv[mi]);
                    if(mv[mi]==0) k+=1;
                }
                mi += 1;
            }
        }
        if(flag){
            while(ni<n){
                if(nv[ni]>k){
                    flag = false;
                    break;
                } else {
                    res.push_back(nv[ni]);
                    if(nv[ni]==0) k+=1;
                }
                ni += 1;
            }
        }
        if(flag){
            while(mi<m){
                if(mv[mi]>k){
                    flag = false;
                    break;
                } else {
                    res.push_back(mv[mi]);
                    if(mv[mi]==0) k+=1;
                }
                mi += 1;
            }
        }
        if(!flag) cout << -1 << endl;
        else {
            for(auto ele : res) cout << ele << " ";
            cout << endl;
        }
    }
    return 0;
}