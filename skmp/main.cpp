#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        string s,p;
        cin>>s>>p;
        int slen=s.size();
        int plen=p.size();

        int freqp[26]={0};
        for(int i=0; i<plen; i++){
            freqp[p[i]-'a']++;
        }

        vector<char> v;

        for(int i=0; i<slen; i++){
            if(freqp[s[i]-'a']>0){
                freqp[s[i]-'a']--;
            }else{
                v.push_back(s[i]);

            }
        }
        sort(v.begin(),v.end());

        int vlen=v.size();

        int i=0;

        while(v[i]<p[0] && i<vlen){
            i++;
        }

        vector<char> res;

        for(int j=0; j<i; j++){
            res.push_back(v[j]);
        }
        int x=0;
        while(v[i]==p[0] && i<vlen){
        	x++;
        	i++;
        }
        char smallest=p[0];
        for(int j=1; j<plen; j++){
        	if(p[j]<smallest){
        		smallest=p[j];
        	}
        }
        if(smallest<p[0]){
        	for(int j=0; j<plen;j++){
	            res.push_back(p[j]);
	        }
	        for(int j=1; j<=x; j++){
	        	res.push_back(p[0]);
	        }
	        for(int j=i; j<vlen; j++){
	            res.push_back(v[j]);
	        }
        }else{
        	for(int j=1; j<=x; j++){
	        	res.push_back(p[0]);
	        }
	        for(int j=0; j<plen;j++){
	            res.push_back(p[j]);
	        }
	        for(int j=i; j<vlen; j++){
	            res.push_back(v[j]);
	        }
        }





        int reslen=res.size();

        for(i=0; i<reslen; i++){
            cout<<res[i];
        }
        cout<< "\n";

    }
    return 0;
}
