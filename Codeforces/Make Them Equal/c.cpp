// https://codeforces.com/contest/1594/problem/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; char c;
    cin>>n>>c;
    string s; cin>>s;
    bool all_same = true;
    int i;
    for(i=0; i<n-1; i++){
        if(s[i] != c){
            all_same = false;
            break;
        }
    }
    if(all_same){
        if(s[n-1] == c) cout << 0 << endl;
        else {
            // cout << "#1: ";
            cout << 1 << endl;
            cout << n-1 << endl;
        }
        return;
    }
    if(s[n-1] == c){
        // cout << "#2: ";
        cout << 1 << endl;
        cout << n << endl;
        return;
    } else {
        for(int i=2; i<=n; i++){
            bool possible = true;
            int idx = i;
            while(idx<=n){
                if(s[idx-1]!=c){
                    possible = false;
                    break;
                }
                idx+=i;
            }
            if(possible){
                // cout << "#3: ";
                cout << 1 << endl;
                cout << i << endl;
                return;
            }
        }
        cout << 2 << endl;
        cout << n-1 << " " << n << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

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