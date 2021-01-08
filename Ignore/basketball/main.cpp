#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int cnta=0, cntb=0, score;
    int n = s.size();
    //cout << "n= " << n << endl;
    int win_score=1;
    for(int i=0; i<n; i=i+2){
        if(s[i]=='A'){
            score = s[i+1]-'0';
            cnta+=score;
        }else{
            score = s[i+1]-'0';
            cntb+=score;
        }
        //cout<< i << " "<<(cnta-cntb)<< "****" << endl;
        if(cnta==10 && cntb==10) win_score=2;
        if(cnta>=11 && (cnta-cntb)>=win_score){
            cout<<'A';
            break;
        }else if(cntb>=11 && (cntb-cnta)>=win_score){
            cout<<'B';
            break;
        }
    }
}
