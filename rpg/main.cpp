#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int p,f;
        cin>>p>>f;
        int cnts, cntw;
        cin>>cnts>>cntw;
        int s,w;
        cin>>s>>w;
        if(s>w){
            int temp=s;
            s=w;
            w=temp;
            temp=cnts;
            cnts=cntw;
            cntw=temp;
        }
        int sp = min(cnts,(p/s));
        int ans=0;
        for(int i=0; i<=sp; i++){
            int wp = min(cntw,((p-s*i)/w));
            int sf = min(cnts-i,(f/s));
            int wf = min(cntw-wp, (f-s*sf)/w);
            ans = max(ans,i+wp+sf+wf);
        }
        cout << ans << endl;
    }
    return 0;
}
