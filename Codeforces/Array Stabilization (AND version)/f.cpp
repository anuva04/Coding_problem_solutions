// https://codeforces.com/problemset/problem/1579/F

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
        int n, d; cin>>n>>d;
        vector<int> arr(n);
        for(int i=0; i<n; i++) cin>>arr[i];
        vector<vector<int>> sequences;
        map<int,bool> visited;
        for(int i=0; i<d; i++){
            if(visited[i]) continue;
            int idx = i;
            vector<int> seq;
            while(visited[idx] == false){
                seq.push_back(arr[idx]);
                visited[idx] = true;
                idx = (idx+d)%n;
            }
            sequences.push_back(seq);
        }
        int res = 0;
        bool isAnsPossible = true;
        for(auto seq : sequences){
            bool isZeroPresent = false, isOnePresent = false;
            for(auto ele : seq){
                if(ele == 1) isOnePresent = true;
                else isZeroPresent = true;

                if(isOnePresent && isZeroPresent) break;
            }
            
            if(isOnePresent && !isZeroPresent){
                isAnsPossible = false;
                break;
            }
            int sz = seq.size();
            if(isZeroPresent && isOnePresent){
                for(int i=0; i<sz; i++){
                    int j=i;
                    int len = 0;
                    while(j<sz && seq[j]==1) j++, len++;
                    i = j;
                    res = max(res, len);
                }
                int slen = 0;
                int idx = 0;
                while(idx<sz && seq[idx]==1) idx++, slen++;
                idx = sz-1;
                int blen = 0;
                while(idx>=0 && seq[idx]==1) idx--, blen++;
                res = max(res, slen+blen);
            }
        }
        if(!isAnsPossible){
            cout << -1 << endl;
            continue;
        }
        cout << res << endl;
    }
    
    return 0;
}