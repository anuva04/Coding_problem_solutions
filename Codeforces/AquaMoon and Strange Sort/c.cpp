// https://codeforces.com/problemset/problem/1546/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> a(n);
        int freq[100005][2];
        memset(freq, 0, sizeof freq);
        for(int i=0; i<n; i++){
            cin>>a[i];
            freq[a[i]][i%2]+=1;
        }
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            freq[a[i]][i%2]-=1;
        }
        bool yes = true;
        vector<string> ans;
        for(int i=0; i<n; i++){
            if(freq[a[i]][0]!=0 || freq[a[i]][1]!=0){
                cout << "no" << endl;
                // ans.push_back("no");
                yes = false;
                break;
            }
        }
        if(yes) cout << "yes" << endl;
        // if(yes) ans.push_back("yes");

        // for(auto ele : ans) cout << ele << endl;
    }
    
    return 0;
}