// https://www.codechef.com/APRIL21B/problems/MEXSTR

#include <bits/stdc++.h>
using namespace std;
#define inf LLONG_MAX
typedef long long int ll;

int main()
{
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        vector<ll> nxt0(n,inf);
        vector<ll> nxt1(n,inf);
        ll zero=inf;
        ll one=inf;
        for(int i=n-1; i>=0; i--){
            nxt0[i] = zero;
            nxt1[i] = one;
            if(s[i]=='0') zero=i;
            else one=i;
        }
        if(zero==inf){
            cout << "0" << endl;
            continue;
        }
        if(one==inf){
            cout << "1" <<endl;
            continue;
        }
        vector<ll> len(n);
        bool found0=false, found1=false;
        ll cnt=0;
        for(int i=n-1; i>=0; i--){
            len[i]=cnt;
            if(s[i]=='0') found0=true;
            if(s[i]=='1') found1=true;
            if(found1&&found0){
                cnt +=1;
                found0=false;
                found1=false;
            }
        }
        
        string ans = "";
        ll curr=one;
        while(1){
            ans.push_back(s[curr]);
            ll pos0 = nxt0[curr];
            ll pos1 = nxt1[curr];
            if(pos0==inf){
                ans.push_back('0');
                break;
            }
            if(pos1==inf){
                ans.push_back('1');
                break;
            }
            if(len[pos0]<=len[pos1]) curr=pos0;
            else curr=pos1;
        }
        cout << ans << endl;
    }
}