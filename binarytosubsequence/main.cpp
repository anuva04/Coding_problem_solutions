#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        string s;
        cin>>s;

        vector<int> z;

        vector<int> ones;
        vector<int>ans;

        for(int i=0; i<n; i++){

            int index=z.size()+ones.size();

            if(s[i]=='0'){
                if(ones.empty()){
                    z.push_back(index);
                }else{
                    index=ones.back();
                    ones.pop_back();
                    z.push_back(index);
                }
            }else{
                if(z.empty()){
                    ones.push_back(index);
                }else{
                    index=z.back();
                    z.pop_back();
                    ones.push_back(index);
                }
            }
            ans.push_back(index);
        }
        cout << z.size()+ones.size()<<endl;
        int len=ans.size();
        for(int i=0; i<len; i++){
            cout<<ans[i]+1 << " ";
        }
        cout<<endl;
    }
    return 0;
}
