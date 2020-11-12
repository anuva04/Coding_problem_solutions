#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
//    Bessie = 0
//    Elsie = 1
//    Mildred = 2
    int n; cin>>n;
    int day, inc;
    string cow;
    int curr_milk[3];
    for(int i=0; i<3; i++){
        curr_milk[i]=7;
    }
    int curr_lead[3];
    for(int i=0; i<3; i++){
        curr_lead[i]=1;
    }
    vector< pair<int, pair<string, int> > > v;
    for(int i=0; i<n; i++){
        cin>>day>>cow>>inc;
        v.push_back(make_pair(day, make_pair(cow, inc)));
    }
    sort(v.begin(), v.end());
//    for(int i=0; i<n; i++){
//        cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
//    }
    int cnt=0;
    for(int i=0; i<n; i++){
        int curr_b = curr_lead[0];
        int curr_e = curr_lead[1];
        int curr_m = curr_lead[2];
        if(v[i].second.first == "Bessie"){
            curr_milk[0]+=v[i].second.second;
        }else if(v[i].second.first == "Elsie"){
            curr_milk[1]+=v[i].second.second;
        }else if(v[i].second.first == "Mildred"){
            curr_milk[2]+=v[i].second.second;
        }
        if(curr_milk[0]>curr_milk[1] && curr_milk[0]>curr_milk[2]){
            curr_lead[0]=1;
            curr_lead[1]=0;
            curr_lead[2]=0;
        }else if(curr_milk[1]>curr_milk[0] && curr_milk[1]>curr_milk[2]){
            curr_lead[0]=0;
            curr_lead[1]=1;
            curr_lead[2]=0;
        }else if(curr_milk[2]>curr_milk[0] && curr_milk[2]>curr_milk[1]){
            curr_lead[0]=0;
            curr_lead[1]=0;
            curr_lead[2]=1;
        }else if(curr_milk[0]==curr_milk[1]){
            if(curr_milk[0]>curr_milk[2]){
                curr_lead[0]=1;
                curr_lead[1]=1;
                curr_lead[2]=0;
            }else if(curr_milk[0]==curr_milk[2]){
                curr_lead[0]=1;
                curr_lead[1]=1;
                curr_lead[2]=1;
            }else{
                curr_lead[0]=0;
                curr_lead[1]=0;
                curr_lead[2]=1;
            }
        }else if(curr_milk[0]==curr_milk[2]){
            if(curr_milk[0]>curr_milk[1]){
                curr_lead[0]=1;
                curr_lead[1]=0;
                curr_lead[2]=1;
            }else if(curr_milk[0]==curr_milk[1]){
                curr_lead[0]=1;
                curr_lead[1]=1;
                curr_lead[2]=1;
            }else{
                curr_lead[0]=0;
                curr_lead[1]=1;
                curr_lead[2]=0;
            }
        }else if(curr_milk[1]==curr_milk[2]){
            if(curr_milk[1]>curr_milk[0]){
                curr_lead[0]=0;
                curr_lead[1]=1;
                curr_lead[2]=1;
            }else if(curr_milk[0]==curr_milk[1]){
                curr_lead[0]=1;
                curr_lead[1]=1;
                curr_lead[2]=1;
            }else{
                curr_lead[0]=1;
                curr_lead[1]=0;
                curr_lead[2]=0;
            }
        }

        if(curr_b!=curr_lead[0] || curr_e!=curr_lead[1] || curr_m!=curr_lead[2]) cnt+=1;
    }
    cout<<cnt;
    return 0;
}
