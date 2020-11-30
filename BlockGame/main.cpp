// http://www.usaco.org/index.php?page=viewproblem2&cpid=664

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int n; cin>>n;
    int res[26]={0};
    for(int i=0; i<n; i++){
        string s1, s2;
        cin>>s1>>s2;
        int freq1[26]={0};
        int freq2[26]={0};
        int s1_len = s1.size();
        int s2_len = s2.size();
        for(int j=0; j<s1_len; j++){
            freq1[s1[j]-'a']++;
        }
        for(int j=0; j<s2_len; j++){
            freq2[s2[j]-'a']++;
        }
        for(int j=0; j<26; j++){
            res[j] = res[j] + max(freq1[j],freq2[j]);
        }
    }
    for(int j=0; j<26; j++){
        cout << res[j] << endl;
    }
    return 0;
}
