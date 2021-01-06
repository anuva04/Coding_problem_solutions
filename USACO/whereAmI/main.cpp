// http://www.usaco.org/index.php?page=viewproblem2&cpid=964

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool is_duplicate(int len){
    set<string> se;
    for(int i=0; i<=n-len; i++){
        if(se.count(s.substr(i,len))>0) return true;
        se.insert(s.substr(i,len));
    }
    return false;
}
int main()
{
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin>>n>>s;
    int res = 1;
    while(is_duplicate(res)==true) res+=1;
    cout << res;
    return 0;
}
