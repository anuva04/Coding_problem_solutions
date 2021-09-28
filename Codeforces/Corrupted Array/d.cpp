// https://codeforces.com/problemset/problem/1512/D

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
        vector<int> b(n+2);
        ll sum = 0;
        for(int i=0; i<n+2; i++){ cin>>b[i]; sum += b[i];}
        sort(b.begin(), b.end());
        bool found = false;
        ll sum_without_last = sum - b[n+1];
        for(int i=0; i<n+1; i++){
            if(sum_without_last - b[i] == b[n+1]){
                found = true;
                for(int j=0; j<n+1; j++){
                    if(j==i) continue;
                    cout << b[j] << " ";
                }
                cout << endl;
                break;
            }
        }
        if(found) continue;
        if(sum - b[n] - b[n+1] == b[n]){
            for(int i=0; i<n; i++) cout << b[i] << " ";
            cout << endl;
            found = true;
        }
        if(!found) cout << -1 << endl;
    }
    
    return 0;
}