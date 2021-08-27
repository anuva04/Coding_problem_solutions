// https://codeforces.com/problemset/problem/1552/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<vector<int>> ranks(n, vector<int>(5));
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++) cin>>ranks[i][j];
        }
        int gold = 0;
        for(int i=1; i<n; i++){
            int win_cnt = 0;
            for(int j=0; j<5; j++){
                if(ranks[gold][j]<ranks[i][j]) win_cnt += 1;
            }
            if(win_cnt < 3) gold = i;
        }
        int flag = true;
        for(int i=0; i<n; i++){
            if(i==gold) continue;
            int win_cnt = 0;
            for(int j=0; j<5; j++){
                if(ranks[gold][j]<ranks[i][j]) win_cnt += 1;
            }
            if(win_cnt < 3){
                flag = false;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
        else cout << gold+1 << endl;
    }
    return 0;
}