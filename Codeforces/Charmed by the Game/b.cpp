// https://codeforces.com/contest/1558/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

set<int> s;

void solve(int a_served, int a_won, int b_served, int b_won){
    for(int x=0; x<=a_served; x++){
        int y = a_won - (a_served - x);
        if(y>=0 && y<=b_served) s.insert(x+y);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--){
        s.clear();
        int a, b; cin>>a>>b;
        solve(ceil((double(a+b)/2)), a, floor(double((a+b)/2)), b);
        solve(floor(double((a+b)/2)), a, ceil((double(a+b)/2)), b);
        cout << s.size() << endl;
        for(auto ele : s){
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}