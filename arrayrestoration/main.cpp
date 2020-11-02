#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> ans;
        for(int d=1; d<=y-x; d++){
            if((y-x)%d != 0) continue;
            vector<int> res;
            bool isx=false;
            int curr=y, n1=n;
            while(n1>0 && curr>=1){
                res.push_back(curr);
                if(curr==x) isx=true;
                --n1;
                curr -= d;
            }
            curr=y;
            while(n1>0){
                curr+=d;
                res.push_back(curr);
                --n1;
            }
            sort(res.begin(),res.end());
            if(n1==0 && isx){
                if(ans.empty() || ans.back()>res.back()){
                    ans=res;
                }
            }
        }
        int len = ans.size();
        for(int i=0; i<len; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
