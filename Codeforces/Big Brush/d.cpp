// https://codeforces.com/contest/1638/problem/D

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<vector<int>> sequence;

bool isValidSq(int i, int j, int r, int c, vector<vector<int>>& a){
    if(i+1>=r || j+1>=c) return false;
    if(a[i][j]==-1 && a[i+1][j]==-1 && a[i][j+1]==-1 && a[i+1][j+1]==-1) return false;
    if(((a[i][j] == a[i+1][j]) || (a[i+1][j] == -1) || (a[i][j] == -1)) 
        && ((a[i][j] == a[i][j+1]) || (a[i][j+1] == -1) || (a[i][j] == -1))
        && ((a[i][j] == a[i+1][j+1]) || (a[i+1][j+1] == -1) || (a[i][j] == -1))
        && ((a[i][j+1] == a[i+1][j]) || (a[i][j+1] == -1) || (a[i+1][j] == -1))
        && ((a[i][j+1] == a[i+1][j+1]) || (a[i][j+1] == -1) || (a[i+1][j+1] == -1))
        && ((a[i+1][j] == a[i+1][j+1]) || (a[i+1][j] == -1) || (a[i+1][j+1] == -1))
        ) return true;

    return false;
}

void dfs(int i, int j, int r, int c, vector<vector<int>>& a){
    if(i<0 || i>=r || j<0 || j>=c) return;
    // if(a[i][j]==-1 && a[i+1][j]==-1 && a[i][j+1]==-1 && a[i+1][j+1]==-1) return;
    if(!isValidSq(i, j, r, c, a)) return;
    // cout << i << ' ' << j << endl;

    if(a[i][j] != -1) sequence.push_back({i, j, a[i][j]});
    else if(a[i+1][j] != -1) sequence.push_back({i, j, a[i+1][j]});
    else if(a[i+1][j+1] != -1) sequence.push_back({i, j, a[i+1][j+1]});
    else sequence.push_back({i, j, a[i][j+1]});

    a[i][j] = a[i+1][j] = a[i][j+1] = a[i+1][j+1] = -1;
    dfs(i-1, j-1, r, c, a);
    dfs(i-1, j, r, c, a);
    dfs(i-1, j+1, r, c, a);
    dfs(i, j+1, r, c, a);
    dfs(i+1, j+1, r, c, a);
    dfs(i+1, j, r, c, a);
    dfs(i+1, j-1, r, c, a);
    dfs(i, j-1, r, c, a);
    return;
}

void solve(){
    int r, c; cin>>r>>c;
    vector<vector<int>> a(r, vector<int>(c));
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin>>a[i][j];
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) dfs(i, j, r, c, a);

    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++){
    //         cout << a[i][j] << ' ';
    //     } cout << endl;
    // }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++){
            if(a[i][j] != -1) {
                cout << -1 << endl;
                return;
            }
        }
    }

    if((int)sequence.size() > (r*c)) {
        cout << -1 << endl;
        return;
    }
    cout << (int)sequence.size() << endl;
    for(int i=(int)sequence.size()-1; i>=0; i--) 
        cout << sequence[i][0]+1 << ' ' << sequence[i][1]+1 << ' ' << sequence[i][2] << endl;
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