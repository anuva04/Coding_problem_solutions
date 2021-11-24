// https://codeforces.com/contest/1605/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int zeros = 0;
    for(char c : s){
        if(c == '0') zeros += 1;
    }
    // cout << zeros << endl;
    vector<int> indices;
    for(int i=0; i<zeros; i++){
        // cout << s[i] << endl;
        if(s[i] == '1') indices.push_back(i+1);
    }
    int misplaced = indices.size();
    if(misplaced == 0){
        cout << 0 << endl;
        return;
    }
    for(int i=n-1; i>=0; i--){
        if(s[i] == '0'){
            indices.push_back(i+1);
            misplaced--;
            if(misplaced<=0) break;
        }
    }
    sort(indices.begin(), indices.end());
    cout << 1 << endl;
    cout << indices.size() << ' ';
    for(auto i : indices) cout << i << ' '; cout << endl;
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