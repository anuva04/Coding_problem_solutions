// https://codeforces.com/contest/1629/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<string> ss(n);
    for(int i=0; i<n; i++) cin>>ss[i];
    set<string> st;
    for(int i=0; i<n; i++){
        string s_rev = ss[i];
        if(s_rev.size() == 1) {
            cout << "YES" << endl;
            return;
        }
        st.insert(ss[i]);
        reverse(s_rev.begin(), s_rev.end());
        if(st.find(s_rev) != st.end()) {
            cout << "YES" << endl;
            return;
        }
    }
    st.clear();
    for(int i=0; i<n; i++){
        string s = ss[i];
        if(s.size() == 3){
            st.insert(s.substr(0, 2));
        } else {
            reverse(s.begin(), s.end());
            if(st.find(s) != st.end()){
                cout << "YES" << endl;
                return;
            }
        }
    }
    st.clear();
    for(int i=n-1; i>=0; i--){
        string s = ss[i];
        if(s.size() == 3){
            st.insert(s.substr(1, 2));
        } else {
            reverse(s.begin(), s.end());
            if(st.find(s) != st.end()){
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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