// https://codeforces.com/problemset/problem/1549/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

// void solve(string s, string t){

// }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string enemy; cin>>enemy;
        string me; cin>>me;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(me[i]!='0'){
                if(enemy[i] == '0'){
                    cnt += 1;
                    enemy[i] = '2';
                } else if((i-1>=0) && (enemy[i-1]=='1')){
                    enemy[i-1]='2';
                    cnt += 1;
                } else if ((i+1<n) && (enemy[i+1]=='1')){
                    enemy[i+1] = '0';
                    cnt += 1;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}