// http://www.usaco.org/index.php?page=viewproblem2&cpid=736

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m; cin>>n>>m;
    string spotty[n];
    for(int i=0; i<n; i++){
        cin>>spotty[i];
    }
    string plain[n];
    for(int i=0; i<n; i++){
        cin>>plain[i];
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        set<char> s;
        for(int j=0; j<n; j++){
            s.insert(spotty[j][i]);
        }
        bool isPresent = false;
        for(int j=0; j<n; j++){
            if(s.find(plain[j][i])!=s.end()){
                isPresent=true;
                break;
            }
        }
        if(isPresent==false) ans++;
    }
    cout << ans;
    return 0;
}
