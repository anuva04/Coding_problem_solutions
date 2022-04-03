// https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

void solve(){
    int r, c; cin>>r>>c;
    cout << "..";
    for(int i=1; i<=c-1; i++) cout << "+-"; cout << "+" << endl;
    cout << "..";
    for(int i=1; i<=c-1; i++) cout << "|."; cout << "|" << endl;
    for(int i=1; i<=c; i++) cout << "+-"; cout << "+" << endl;

    for(int i=1; i<=r-1; i++){
        for(int i=1; i<=c; i++) cout << "|."; cout << "|" << endl;
        for(int i=1; i<=c; i++) cout << "+-"; cout << "+" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int test; cin>>test;

    for(int t=1; t<=test; t++){
        cout << "Case #" << t << ": " << endl;
        solve();
    }
    
    return 0;
}