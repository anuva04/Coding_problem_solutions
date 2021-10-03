// https://codeforces.com/problemset/problem/1506/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int solve(string& s, int n, int k){
    int left = 0, right = n-1;
    int cnt=1;
    while(left<n && s[left] != '*') left +=1;
    while(true){
        int right = min(n-1, left+k);
        while(right>left && s[right]=='.') right-=1;
        if(right == left) break;
        cnt += 1;
        left = right;
    }
    return cnt;
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
        int n, k;
        cin>>n>>k;
        string s; cin>>s;
        int cnt1 = solve(s, n, k);
        cout << cnt1 << endl;
    }
    
    return 0;
}