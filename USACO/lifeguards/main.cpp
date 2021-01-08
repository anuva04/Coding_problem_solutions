// http://www.usaco.org/index.php?page=viewproblem2&cpid=784

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n; cin>>n;
    bool arr[1001];

    vector<pair<int,int> > vec;
    for(int i=0; i<n; i++){
        int start_time, end_time;
        cin>>start_time>>end_time;
        vec.push_back(make_pair(start_time,end_time));
    }
    int max_time=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<=1000; j++) arr[j]=false;
        for(int j=0; j<n; j++){
            if(j!=i){
                for(int k=vec[j].first + 1; k<=vec[j].second; k++) arr[k]=true;
            }
        }
        int cnt=0;
        for(int j=1; j<=1000; j++){
            if(arr[j]==true) cnt++;
        }
        max_time = max(max_time, cnt);
    }
    cout << max_time;
    return 0;
}
