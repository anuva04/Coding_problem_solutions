// https://codeforces.com/problemset/problem/1493/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> reflections = {0,1,5,-1,-1,2,-1,-1,8,-1};

int findNextValid(int num){
    string s = to_string(num);
    if((int)s.size() == 1) s = "0" + s;
    string ans = "";
    for(int i=1; i>=0; i--){
        if(reflections[s[i]-'0'] == -1) return INT_MAX;
        ans += char(reflections[s[i]-'0']+'0');
    }
    return stoi(ans);
}

string standardise(int x){
    string s = to_string(x);
    if(x<10){
        s = "0"+s;
    }
    return s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        int h,m; cin>>h>>m;
        string time; cin>>time;
        int hour = (time[0]-'0')*10 + (time[1]-'0');
        int min = (time[3]-'0')*10 + (time[4]-'0');
        while(true){
            if(min == m){
                hour++;
                min=0;
            }
            if(hour == h) hour = 0;
            // cout << hour << " " << min << " " << findNextValid(hour) << " " << findNextValid(min) << endl;
            if(findNextValid(hour)<m && findNextValid(min)<h){
                cout << standardise(hour) << ":" << standardise(min) << endl;
                break;
            }
            min++;
        }
    }

    return 0;
}