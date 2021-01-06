// https://codeforces.com/problemset/problem/1398/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        string s; cin>>s;
        int len=s.size();
        vector<int> res;
        int i=0;
        int cnt=0;
        while(i<len){
            if(s[i]=='0')i++;
            else{
                while(s[i]=='1'){
                    cnt++;
                    i++;
                }
                if(cnt>=1) res.push_back(cnt);
                cnt=0;
                i++;
            }
        }
        sort(res.begin(),res.end());
        int ans=0;
        for(int i=res.size()-1; i>=0; i=i-2){
            ans+=res[i];
        }
        cout << ans <<endl;
    }
    return 0;
}
