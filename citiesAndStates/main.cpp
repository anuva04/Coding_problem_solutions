// http://www.usaco.org/index.php?page=viewproblem2&cpid=667

#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n; cin>>n;
    map<string, int> mp;
    ll res=0;
    for(int i=0; i<n; i++){
        string city, state_code;
        cin>>city>>state_code;
        city = city.substr(0,2);
        if(city!=state_code){
            res+=mp[state_code+city];
        }
        mp[city+state_code]+=1;
    }
    cout << res;
    return 0;
}
