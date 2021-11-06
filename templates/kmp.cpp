#include <bits/stdc++.h>
using namespace std;

vector<int> computeLps(string& pattern){
    int len = pattern.size();
    vector<int> lps(len);
    int j = 0;
    lps[0] = 0;
    for(int i=1; i<len; i++){
        if(pattern[i] == pattern[j]){
            lps[i] = j+1;
            j++; i++;
        } else {
            if(j!=0) j = lps[j-1];
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

bool kmp(string& text, string& pattern){
    vector<int> lps = computeLps(pattern);
    int i=0, j=0;
    while(i<(int)text.size() && j<(int)pattern.size()){
        if(text[i] == pattern[j]){
            i++; j++;
        } else {
            if(j!=0) j = lps[j-1];
            else i++;
        }
    }
    if(j == (int)pattern.size()) return true;
    return false;
}

int main(){
    string text, pattern;
    cin>>text>>pattern;
    if(kmp(text, pattern)) cout << "Pattern found in string!" << endl;
    else cout << "Pattern not found in string!" << endl;
}