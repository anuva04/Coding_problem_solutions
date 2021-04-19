// https://codingcompetitions.withgoogle.com/codejam/round/000000000043585d/00000000007549e5

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string add1(string &s){
    for(int j=s.size()-1; j>=0; j--){
        if(j==0){
            int digit = s[j]-'0';
            if(digit<9){
                digit += 1;
                s[j] = digit+'0';
            }else {
                s[j] = '0';
                s.insert(0, "1");
            }
            return s;
        }
        int digit = s[j]-'0';
        if(digit<9){
            digit += 1;
            s[j] = digit+'0';
            return s;
        }
        else {
            s[j] = '0';
        }
    }
}

int compare(string s1, string s2){
	if(s1.length()>s2.length()) return 1;
	if(s2.length()>s1.length()) return -1;
	for(int i=0; i<s1.length(); i++){
		if(s1[i]-'0'>s2[i]-'0') return 1;
		if(s1[i]-'0' < s2[i]-'0') return -1;
	}
	return 0;
}

int main(){
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        int n; cin>>n;
        vector<string> v(n);
        for(int i=0; i<n; i++){
            int x; cin>>x;
            string s = to_string(x);
            v[i] = s;
        }
        ll cnt=0;
        for(int i=1; i<n; i++){
            if(compare(v[i-1],v[i])==-1){
            	continue;
            }
            else{
                if(compare(v[i-1],v[i])==0){
                    v[i] += "0";
                    cnt += 1;
                }
                else{
                    ll len_diff = v[i-1].length()-v[i].length();
                    string x1=v[i];
                    for(int j=1; j<=len_diff; j++) x1 += "0";
                    if(compare(x1, v[i-1])==1){
                        v[i]=x1;
                        cnt += len_diff;
                        continue;
                    }
                    string x2 = v[i];
                    for(int j=1; j<=len_diff; j++) x2 += "9";
                    if(compare(x2, v[i-1])==-1 || compare(x2, v[i-1])==0){
                        v[i] = x1;
                        v[i] += "0";
                        cnt += (len_diff+1);
                        continue;
                    }
                    string x3 = add1(v[i-1]);
                    cnt += (x3.length()-v[i].length());
                    v[i] = x3;
                }
            }
        }
        cout << "Case #" << tt << ": " << cnt << endl;
    }
}