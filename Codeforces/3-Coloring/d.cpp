// https://codeforces.com/contest/1504/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

void getNextValidCell(pair<int,int>& free, int n){
    if(n&1){
        if(free.second == n-1){
            free.second = 1;
            free.first += 1;
        } else if(free.second == n-2){
            free.second = 0;
            free.first += 1;
        } else free.second += 2;
    } else {
        if(free.second == n-1){
            free.second = 0;
            free.first += 1;
        } else if(free.second == n-2){
            free.second = 1;
            free.first += 1;
        } else free.second += 2;
    }
}

void solve(){
    int n; cin>>n;
    int lim = n*n;
    pair<int,int> free_b = {0,0}, free_w = {0,1};
    while(lim--){
        int color; cin>>color;
        if(color == 1){
            if(free_b.first < n && free_b.second < n){
                cout << 2 << ' ' << free_b.first+1 << ' ' << free_b.second+1 << endl;
                getNextValidCell(free_b, n);
            } else {
                cout << 3 << ' ' << free_w.first+1 << ' ' << free_w.second+1 << endl;
                getNextValidCell(free_w, n);
            }
        } else if(color == 2){
            if(free_w.first < n && free_w.second < n){
                cout << 1 << ' ' << free_w.first+1 << ' ' << free_w.second+1 << endl;
                getNextValidCell(free_w, n);
            } else {
                cout << 3 << ' ' << free_b.first+1 << ' ' << free_b.second+1 << endl;
                getNextValidCell(free_b, n);
            }
        } else {
            if(free_w.first < n && free_w.second < n){
                cout << 1 << ' ' << free_w.first+1 << ' ' << free_w.second+1 << endl;
                getNextValidCell(free_w, n);
            } else {
                cout << 2 << ' ' << free_b.first+1 << ' ' << free_b.second+1 << endl;
                getNextValidCell(free_b, n);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}