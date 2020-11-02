#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s; cin>>s;
        int count_zero=0;
        int size_s = s.size();
        for(int i=0; i<s.size();  i++){
            if(s[i]=='0') count_zero++;
        }
        vector<int> side;
        vector<int> v;
        int i=0;
        while(s[i]!='1') i++;
        if(i!=0) side.push_back(i);
        s.erase(0,i);
        reverse(s.begin(),s.end());
        i=0;
        while(s[i]!='1') i++;
        if(i!=0) side.push_back(i);
        s.erase(0,i);
        int siz = s.size();
        while(siz>0){
            i=0;
            while(s[i]!='0' && i<siz) i++;
            s.erase(0,i);
            siz = s.size();
            i=0;
            while(s[i]!='1' && i<siz) i++;
            if(i!=0) v.push_back(i);
            s.erase(0,i);
            siz=s.size();
        }
        sort(v.begin(),v.end(), greater<int>());
        sort(side.begin(),side.end(), greater<int>());

        for(auto it: v) cout<< "**" << it<< " ";
        cout<<endl;
        for(auto it1 : side) cout<< "******" << it1<< " ";
        cout<<endl;
        int cuts=0, cnts=0, zeros=0;
        if(count_zero==0 || count_zero==size_s) cout<<0<<endl;
        else if(k==0) cout<<accumulate(v.begin(),v.end(), 0)+accumulate(side.begin(),side.end(), 0)<<endl;
        else{
            if(k%2!=0){
                k-=1;
                if(side.size()!=0){
                    cuts+=side[0];
                    cnts+=1;

                }
            }
            i=0;
            for(i=0; i<v.size(); i++){
                if(k>2){
                    cuts+=v[i];
                    k-=2;
                }else break;
            }
            int sum_side = 0;
            if(k>=2){
                if(i<v.size()){
                    for(int j=cnts; j<side.size(); j++) sum_side+=side[j];
                    cuts+=max(sum_side, v[i]);
                }else{
                    for(int j=cnts; j<side.size(); j++) sum_side+=side[j];
                    cuts+=sum_side;
                }

            }
        }
        cout<<accumulate(v.begin(),v.end(), 0)+accumulate(side.begin(),side.end(), 0)-cuts<<endl;
    }
    return 0;
}
