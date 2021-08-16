// https://www.codechef.com/AUG21B/problems/CHARGE

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int duration[n], deadline[n];
        for(int i=0; i<n; i++) cin>>duration[i];
        for(int i=0; i<n; i++) cin>>deadline[i];

        vector<pair<int, pair<int,int>>> dl_dur_idx;

        for(int i=0; i<n; i++){
            dl_dur_idx.push_back({deadline[i], {duration[i], i+1}});
        }
        sort(dl_dur_idx.begin(), dl_dur_idx.end());

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > dur_dl_idx;
        vector<pair<int, pair<int,int>>> schedule;

        for(int i=n-1; i>=0; i--){
            int time = dl_dur_idx[i].first - (i ? dl_dur_idx[i-1].first : 0);
            int r = dl_dur_idx[i].first;
            dur_dl_idx.push({dl_dur_idx[i].second.first, {dl_dur_idx[i].first, dl_dur_idx[i].second.second}});
            while(time && !dur_dl_idx.empty()){
                auto ele = dur_dl_idx.top();
                dur_dl_idx.pop();

                if(ele.first <= time){
                    int t1 = time;
                    time -= ele.first;
                    schedule.push_back({ele.second.second, {r-ele.first, r}});
                    r -= ele.first;
                } else {
                    schedule.push_back({ele.second.second, {r-time, r}});
                    r -= time;
                    dur_dl_idx.push({ele.first - time, {ele.second.first, ele.second.second}});
                    time = 0;
                }
            }
        }

        map<int, int> idx_time;
        for(auto ele : schedule){
            if(idx_time.find(ele.first) == idx_time.end()){
                idx_time[ele.first] = ele.second.second - ele.second.first;
            } else {
                idx_time[ele.first] += ele.second.second - ele.second.first;
            }
        }

        vector<pair<int,int>> new_schedule;

        for(auto ele : idx_time){
            if(ele.second == duration[ele.first-1]){
                new_schedule.push_back({deadline[ele.first-1], ele.first});
            }
        }

        sort(new_schedule.begin(), new_schedule.end());

        cout << new_schedule.size() << endl;

        int time = 0;
        for(auto ele : new_schedule){
            cout << ele.second << " " << time << " " << time+duration[ele.second-1] << endl;
            time += duration[ele.second-1];
        }
    }
}