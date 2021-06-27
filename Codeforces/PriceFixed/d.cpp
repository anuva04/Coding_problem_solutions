// https://codeforces.com/problemset/problem/1539/D
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int32_t main(){
    int n; cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    int rubles = 0, exp=0;
    int i=0, j=n-1;
    while(i<j){
        if(v[j].second<=exp || v[j].first==0){
            rubles += v[j].first;
            exp+=v[j].first;
            j-=1;
        } else if(v[i].second<=exp){
            rubles += v[i].first;
            exp+=v[i].first;
            i+=1;
        } else {
            int required_exp = max(v[i].second - exp, (int)0);
            int num_of_products = min(required_exp, v[j].first);
            exp += num_of_products;
            rubles += (2*num_of_products);
            v[j].first -= num_of_products;
        }
    }

    if(v[i].second <= exp){
        exp += v[i].first;
        rubles += v[i].first;
    } else {
        int required_exp = max(v[i].second - exp, (int)0);
        int num_of_products = min(required_exp, v[j].first);
        exp += num_of_products;
        rubles += (2*num_of_products);
        v[i].first -= num_of_products;
        if(v[i].first > 0){
            exp += v[i].first;
            rubles += v[i].first;
        }
    }
    cout << rubles << endl;
}