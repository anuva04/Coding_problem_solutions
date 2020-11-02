#include <bits/stdc++.h>

using namespace std;
int solve(string s, int x, int y){
    int ans=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]-'0' == x){
            ans++;
            swap(x,y);
        }
    }
    if(x!=y && ans%2==1){
        ans--;
    }
    return ans;
}
int main()
{
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int result=0;
        for(int i=0; i<=9; i++){
            for(int j=0; j<=9; j++){
                result=max(result,solve(s,i,j));
            }
        }
        cout << s.size()-result <<endl;
    }
    return 0;
}
