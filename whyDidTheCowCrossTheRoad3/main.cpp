#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n; cin>>n;
    vector<pair<int, int> > v;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    int curr_cow_time=v[0].first, curr_time=v[0].second+v[0].first;
    for(int i=1; i<n; i++){
        curr_cow_time=v[i].first;
//        cout<< "curr_cow_time= " << curr_cow_time << endl;
//        cout << "curr_time = " << curr_time <<endl;
//        cout << "************" <<endl;
        if(curr_cow_time<curr_time){
            curr_time+=v[i].second;
        }else{
            curr_time=v[i].second+v[i].first;
        }
    }
    cout<<curr_time;
    return 0;
}
