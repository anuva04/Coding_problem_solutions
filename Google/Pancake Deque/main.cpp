// https://codingcompetitions.withgoogle.com/codejam/round/000000000087711b/0000000000acd59d

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1e9;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    int ans = 0, i = 0, j = n-1, curr_max = INT_MIN;
    while(i<=j){
        if(a[i] < a[j]){
            if(a[i] >= curr_max) {
                ans++;
                curr_max = max(curr_max, a[i]);
            }
            i++;
        } else {
            if(a[j] >= curr_max){
                ans++;
                curr_max = max(curr_max, a[j]);
            }
            j--;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ll test; cin>>test;
    for(ll t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}