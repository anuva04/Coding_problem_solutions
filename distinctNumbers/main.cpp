#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    set<int> s;
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        s.insert(val);
    }
    cout << s.size();
    return 0;
}
