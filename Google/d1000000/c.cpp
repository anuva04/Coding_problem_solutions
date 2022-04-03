// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

void solve(){
    int n; cin>>n;
    vector<int> s(n);
    for(int i=0; i<n; i++) cin>>s[i];
    sort(s.begin(), s.end());
    int cnt = 0, curr = 0;
    for(int i=0; i<n; i++){
        if(s[i] > curr){
            cnt++;
            curr++;
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test; cin>>test;

    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}