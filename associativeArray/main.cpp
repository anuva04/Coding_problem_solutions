https://judge.yosupo.jp/problem/associative_array

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    map<ll, ll> mp;
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int queryType; cin>>queryType;
        if(queryType==0){
            ll k, v;
            cin>>k>>v;
            if(mp.count(k)==1) mp.erase(k);
            mp.insert({k,v});
        }else{
            ll k; cin>>k;
            if(mp.count(k)==0) cout << 0 << endl;
            else cout << mp[k] << endl;
        }
    }
    return 0;
}
