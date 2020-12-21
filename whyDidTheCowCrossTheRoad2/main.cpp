// http://www.usaco.org/index.php?page=viewproblem2&cpid=712

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string s; cin>>s;
    int start_point[26], end_point[26];
    for(int i=0; i<26; i++){
        start_point[i]=-1;
        end_point[i]=-1;
    }
    for(int i=0; i<52; i++){
        if(start_point[s[i]-'A'] == -1) start_point[s[i]-'A']=i;
        else end_point[s[i]-'A'] = i;
    }
//    for(int i=0; i<26; i++) cout << start_point[i] << " ";
//    cout << endl;
//    for(int i=0; i<26; i++) cout << end_point[i] << " ";
//    cout << endl;
    int cnt=0;
    for(int i=0; i<25; i++){
        for(int j=i+1; j<26; j++){
            if((start_point[i]<start_point[j] && end_point[i]>start_point[j] && end_point[i]<end_point[j]) || (start_point[j]<start_point[i] && end_point[j]>start_point[i] && end_point[j]<end_point[i])){
                cnt++;
                // cout << "i= " << i << " j= " << j << " " << start_point[i] << " " << end_point[i] << " " << start_point[j] << " " << end_point[j] <<endl;
            }
        }
    }
    cout << cnt;
    return 0;
}
