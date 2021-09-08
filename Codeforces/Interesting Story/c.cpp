// https://codeforces.com/problemset/problem/1551/C

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
        vector<int> freq[26];
        for(int i=0; i<n; i++){
            string s; cin>>s;
            int balance = -(int)s.length();
            for(int j=0;j<26; j++){
                freq[j].push_back(balance);
            }
            for(auto c : s){
                freq[c - 'a'].back() += 2;
            }
        }
        int maxCnt = 0;
        int bestLetter = 0;
        for(int i=0; i<26; i++){
            auto chars = freq[i];
            sort(chars.begin(), chars.end());
            reverse(chars.begin(), chars.end());
            if(chars[0] <= 0) continue;
            int sum = chars[0];
            int j = 1;
            for(; j<n && sum>0; j++){
                sum += chars[j];
            }
            if(sum <= 0) j--;
            if(j>maxCnt) {
                maxCnt = j;
                bestLetter = i;
            }
        }
        cout << maxCnt << endl;
    }

    return 0;
}