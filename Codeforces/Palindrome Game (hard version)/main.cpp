// https://codeforces.com/problemset/problem/1527/B2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

bool isPalin(string s, int n){
    int l=0, r=n-1;
    while(l<=r){
        if(s[l]!=s[r]) return false;
        l+=1;
        r-=1;
    }
    return true;
}

void solveb1(string s, int n){
    int cntz=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0') cntz+=1;
    }
    if(cntz==0){
        cout << "DRAW" << endl;
        return;
    }
    if(cntz==1){
        cout << "BOB" << endl;
        return;
    }
    if(n&1){
        if(s[n/2]=='0') cout << "ALICE" << endl;
        else cout << "BOB" << endl;
    } else cout << "BOB" << endl;
    return;
}

void solveb2(string s, int n){
    int cntz=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0') cntz+=1;
    }
    if(cntz!=2){
        cout << "ALICE" << endl;
        return;
    }
    if((s[n/2]=='0'&&(n&1)) || (s[n/2]=='0'&&(n&1))){
        cout << "DRAW" << endl;
    } else cout << "ALICE" << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        if(isPalin(s,n)) solveb1(s,n);
        else solveb2(s,n);
    }

    return 0;
}