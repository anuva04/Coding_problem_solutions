// https://codeforces.com/contest/1569/problem/As
 
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        string s; cin>>s;
        vector<int> freq(n, 0);
        if(s[0] == 'a') freq[0] = 1;
        for(int i=1; i<n; i++){
            if(s[i] == 'a') freq[i] = freq[i-1]+1;
            else freq[i] = freq[i-1];
        }
        bool found = false;
        for(int l=0; l<n; l++){
            for(int r=l; r<n; r++){
                int as = freq[r];
                if(l>0) as -= freq[l-1];
                int bs = (r-l+1)-as;
                if(as == bs) {cout << l+1 << " " << r+1 << endl; found = true; break;}
            }
            if(found) break;
        }
        if(!found) cout << -1 << " " << -1 << endl;
    }
 
    return 0;
}