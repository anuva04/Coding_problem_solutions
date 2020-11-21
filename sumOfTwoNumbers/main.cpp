#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    map<int, int> mp;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int flag=0;
    for(int i=0; i<n; i++){
        if(mp.count(x-v[i])==1){
            cout << i+1 << " " << mp[x-v[i]];
            flag=1;
            break;
        }else{
            mp.insert({v[i], i+1});
        }
    }
    if(flag==0) cout << "IMPOSSIBLE";
    return 0;
}
