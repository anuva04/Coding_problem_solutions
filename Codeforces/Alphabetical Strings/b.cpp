// https://codeforces.com/problemset/problem/1547/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll test; cin>>test;
    while(test--){
        string s; cin>>s;
        int n = s.length();
        int idx = -1;
        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            cout << "NO" << endl;
            continue;
        }
        int left = idx-1, right = idx+1;
        char chr = 'b';
        int n1 = n - 1;
        bool flag = true;
        while(n1--){
            if((left>=0) && s[left] == chr){
                left -= 1;
                chr += 1;
            } else if((right<n) && s[right] == chr){
                right += 1;
                chr += 1;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}