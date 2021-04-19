// https://codingcompetitions.withgoogle.com/codejamio/round/00000000004360f2/00000000007772ed

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        int n; cin>>n;
        int block[n];
        for(int i=0; i<n; i++) cin>>block[i];
        string ans = "A";
        for(int i=0; i<n; i++){
            if(i%2==0){
                int lim = block[i];
                for(int j=1; j<lim; j++){
                    ans += (ans[ans.size()-1]+1);
                }
                if(i<n-1){
                    char lastLetter = ans[ans.size()-1]+1;
                    char expectedLast = 'A'+block[i+1];
                    if(expectedLast>lastLetter) ans += expectedLast;
                    else ans += lastLetter;
                }else{
                    ans += (ans[ans.size()-1]+1);
                }
            } else {
                int lim = block[i];
                for(int i=lim; i>0; i--){
                    ans += ('A'+i-1);
                }
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
}