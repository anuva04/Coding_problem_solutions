// https://codeforces.com/problemset/problem/1395/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int j=0; j<m; j++) cin>>b[j];
    int lim = pow(2,9) - 1;
    for(int A=0; A<lim; A++){
        bool ok = true;
        for(int i=0; i<n; i++){
            bool okk = false;
            for(int j=0; j<m; j++){
                if(((a[i] & b[j]) | A) == A) {
                    okk = true;
                    break;
                }
            }
            if(!okk) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << A << endl;
            return;
        }
    }
    cout << lim << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}