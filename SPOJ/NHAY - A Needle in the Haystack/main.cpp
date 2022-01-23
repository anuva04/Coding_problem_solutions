// 

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void kmp(const string& needle, const string& hay){
    int m = needle.size();
    vector<int> prefix_suffix(m+1);
    prefix_suffix[0] = -1;
    for (int i = 0; i < m; ++i){
        prefix_suffix[i+1] = prefix_suffix[i];
        while(prefix_suffix[i+1] > -1 && needle[prefix_suffix[i+1]] != needle[i]){
            prefix_suffix[i+1] = prefix_suffix[prefix_suffix[i+1]];
        }
        prefix_suffix[i+1]++;
    }
    int n = hay.size();
    int matching_length = 0;
    for (int i = 0; i < n; ++i){
        while(matching_length>-1 && needle[matching_length] != hay[i])
            matching_length = prefix_suffix[matching_length];
        
        if(++matching_length == m){ 
            cout << i-m+1 << endl;
            matching_length = prefix_suffix[m];
        }
    }
}

void solve(){
    int m;
    bool first = true;
    while(cin>>m){
        if(!first) cout << endl;
        first = false;

        string needle, hay;
        cin>>needle;
        cin>>hay;
        kmp(needle, hay);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}