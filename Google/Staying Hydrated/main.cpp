// https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int k; cin>>k;
    vector<int> x, y;
    for(int i=0; i<k; i++){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        x.push_back(x1);
        x.push_back(x2);
        y.push_back(y1);
        y.push_back(y2);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int xx = x.size()/2 - 1;
    int yy = y.size()/2 - 1;
    cout << x[xx] << " " << y[yy] << endl;
}

int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    ll test; cin>>test;
    // while(test--){
    //     solve();
    // }
    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}