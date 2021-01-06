// https://cses.fi/problemset/task/1622

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void permute(string s, int l, int r, set<string> &se){
    if(l==r) se.insert(s);
    else{
        for(int i=l; i<=r; i++){
            swap(s[l], s[i]);
            permute(s, l+1, r, se);
            swap(s[l], s[i]);
        }
    }
}
int main()
{
    string s;
    cin>>s;
    int n = s.length();
    sort(s.begin(), s.end());
    set<string> se;
    permute(s, 0 , n-1, se);
    cout << se.size() << endl;
    set<string>::iterator it;
    for(it=se.begin(); it!=se.end(); it++) cout << *it << endl;
    return 0;
}
