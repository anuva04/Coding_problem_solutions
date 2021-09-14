// https://codeforces.com/problemset/problem/1536/B

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
        int n; cin>>n;
        string s; cin>>s;
        set<string> substrings;
        for(int i=0; i<n; i++){
            string ss;
            for(int k=0; k<5 && i+k<n; k++){
                ss.push_back(s[i+k]);
                substrings.insert(ss);
            }
        }
        bool found = false;
        for(int len=1; len<6; len++){
            string candidate_mex(len, 'a');
            while(true){
                if(substrings.count(candidate_mex)==0){
                    cout << candidate_mex << endl;
                    found = true;
                    break;
                }
                if(found) break;
                int idx = len - 1;
                while(idx>=0 && candidate_mex[idx]=='z'){
                    candidate_mex[idx] = 'a';
                    idx--;
                }
                if(idx<0) break;
                candidate_mex[idx]++;
            }
            if(found) break;
        }
    }

    return 0;
}