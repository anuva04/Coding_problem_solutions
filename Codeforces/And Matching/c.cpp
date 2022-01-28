// // 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int invert(int n){
    int len = log2(n)  + 1;
    for(int i=0; i<len; i++) n = ( n ^ (1<<i));
    return n;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<bool> taken(n, false);
    vector<pair<int,int>> ans;
    if(n-1 == k){
        if(n==4) cout << -1 << endl;
        else {
            ans.push_back({n-1, n-2});
            ans.push_back({n-3, 1});
            ans.push_back({0, 2});
            taken[n-1] = true;
            taken[n-2] = true;
            taken[n-3] = true;
            taken[0] = true;
            taken[1] = true;
            taken[2] = true;
            for(int i=n-4; i>=3; i--){
                if(taken[i]) continue;
                int x = invert(i);
                ans.push_back({x, i});
                taken[x] = true;
                taken[i] = true;
            }
        }
    } else {
        ans.push_back({k, n-1});
        taken[k] = true;
        taken[n-1] = true;
        for(int i=n-2; i>=0; i--){
            if(taken[i]) continue;
            int x = invert(i);
            if(taken[x]){
                ans.push_back({0, i});
                taken[0] = true;
                taken[i] = true;
            } else {
                ans.push_back({x, i});
                taken[i] = true;
                taken[x] = true;
            }
        }
    }
    // int val = 0;
    for(auto ele : ans){
        cout << ele.first << ' ' << ele.second << endl;
        // val += (ele.first & ele.second);
    }
    // cout << "val: " << val << endl;
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

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int invert(int n){
    int len = log2(n)  + 1;
    for(int i=0; i<len; i++) n = ( n ^ (1<<i));
    return n;
}

void solve(){
    int n, k; cin>>n>>k;
    vector<bool> taken(n, false);
    vector<pair<int,int>> ans;
    if(n-1 == k){
        if(n==4) cout << -1 << endl;
        else {
            ans.push_back({n-1, n-2});
            ans.push_back({n-3, 1});
            ans.push_back({0, 2});
            taken[n-1] = true;
            taken[n-2] = true;
            taken[n-3] = true;
            taken[0] = true;
            taken[1] = true;
            taken[2] = true;
            for(int i=n-4; i>=3; i--){
                if(taken[i]) continue;
                int x = invert(i);
                ans.push_back({x, i});
                taken[x] = true;
                taken[i] = true;
            }
        }
    } else {
        ans.push_back({k, n-1});
        taken[k] = true;
        taken[n-1] = true;
        for(int i=n-2; i>=0; i--){
            if(taken[i]) continue;
            int x = invert(i);
            if(taken[x]){
                ans.push_back({0, i});
                taken[0] = true;
                taken[i] = true;
            } else {
                ans.push_back({x, i});
                taken[i] = true;
                taken[x] = true;
            }
        }
    }
    // int val = 0;
    for(auto ele : ans){
        cout << ele.first << ' ' << ele.second << endl;
        // val += (ele.first & ele.second);
    }
    // cout << "val: " << val << endl;
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