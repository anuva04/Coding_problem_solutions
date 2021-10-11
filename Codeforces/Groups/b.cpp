// https://codeforces.com/contest/1598/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void solve(){
    int n; cin>>n;
    vector<vector<int>> days(n, vector<int>(5));
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++) cin>>days[i][j];
    }
    int possible = false;
    for(int day1=0; day1<5; day1++){
        for(int day2=day1+1; day2<5; day2++){
            int cntday1=0, cntday2=0, cntnone=0;
            for(int i=0; i<n; i++){
                if(days[i][day1]==1) cntday1++;
                if(days[i][day2]==1) cntday2++;
                if(days[i][day1]==0 && days[i][day2]==0) cntnone++;
            }
            if((cntday1 >= n/2) && (cntday2 >= n/2) && (cntnone==0)){
                possible = true;
                break;
            }
        }
        if(possible) break;
    }
    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}