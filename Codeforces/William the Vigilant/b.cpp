// https://codeforces.com/contest/1609/problem/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool isPartOfSubstring(string& s, int pos, int n){
    if(s[pos] == 'a'){
        if(pos+1>=n || pos+2>=n || s[pos+1]!='b' || s[pos+2]!='c') return false;
        return true;
    }
    else if(s[pos] == 'b'){
        if(pos-1<0 || pos+1>=n || s[pos-1]!='a' || s[pos+1]!='c') return false;
        return true;
    }
    else {
        if(pos-1<0 || pos-2<0 || s[pos-1]!='b' || s[pos-2]!='a') return false;
        return true;
    }
}

void solve(){
    int n, q; cin>>n>>q;
    string s; cin>>s;
    int k = 0;
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            if(isPartOfSubstring(s, i, n)) k++;
        }
    }
    // cout << k << endl;
    while(q--){
        int pos;
        char cc;
        cin>>pos>>cc;
        pos -= 1;
        // cout << s << ' ';
        if(s[pos] == cc){
            cout << k << endl;
            continue;
        }
        if(isPartOfSubstring(s, pos, n)){
            s[pos] = cc;
            if(!isPartOfSubstring(s, pos, n)) k-=1;
        } else {
            s[pos] = cc;
            if(isPartOfSubstring(s, pos, n)) k += 1;
        }
        // cout << s << endl;
        cout << k << endl;
    }
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
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}