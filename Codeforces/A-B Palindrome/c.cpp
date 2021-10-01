// https://codeforces.com/problemset/problem/1512/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        int a, b; cin>>a>>b;
        string s; cin>>s;
        int n =  s.size();
        bool possible = true;
        for(int i=0; i<(n/2); i++){
            if(a<0 || b<0){
                possible = false;
                break;
            }
            if(s[i]=='0' && s[n-i-1]=='0') a-=2; 
            else if(s[i]=='1' && s[n-i-1]=='1') b-=2;
            else if(s[i]=='?' && s[n-i-1]=='?') continue;
            else if(s[i]=='?'){
                if(s[n-i-1]=='0'){
                    s[i] = '0';
                    a-=2;
                }else if(s[n-i-1]=='1'){
                    s[i]='1'; b-=2;
                }
            }else if(s[n-i-1]=='?'){
                if(s[i]=='0'){
                    s[n-i-1] = '0';
                    a-=2;
                } else if(s[i] == '1'){
                    s[n-i-1] = '1';
                    b-=2;
                }
            }else{
                possible = false;
                break;
            }
        }
        if(!possible){
            cout << -1 << endl;
            continue;
        }
        if(n%2 == 1){
            if(s[n/2]=='0') a-=1;
            else if(s[n/2]=='1') b-=1;
        }
        for(int i=0; i<(n/2); i++){
            if(s[i]!='?') continue;
            if(a>=2){
                s[i] = s[n-i-1] = '0';
                a-=2;
            } else if(b>=2){
                s[i] = s[n-i-1] = '1';
                b-=2;
            }else{
                possible = false;
                break;
            }
        }
        if(!possible) {
            cout << -1 << endl;
            continue;
        }
        if(n%2 == 1){
            if(s[n/2]=='?'){
                if(a>0){
                    s[n/2]='0';
                    a-=1;
                } else if(b>0){
                    s[n/2]='1';
                    b-=1;
                }else{
                    possible = false;
                }
            }
        }
        if(!possible) {
            cout << -1 << endl;
            continue;
        }
        if(a!=0 || b!=0){
            cout << -1 << endl;
        } else cout << s << endl;
    }
    
    return 0;
}