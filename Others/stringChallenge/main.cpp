#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool strChallenge(string str){
    string s1 = str;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);

    size_t str1 = s1.find("password");
    if(str1 != string::npos) return false;

    if(str.size()<=7 || str.size()>= 31) return false;
    bool isCapital = false, isNumber = false, isSymbol = false;
    for(int i=0; i<str.size(); i++){
        if(str[i] >= 65 && str[i]<=90) isCapital = true;
        if(str[i]>=48 && str[i]<=57) isNumber = true;
        if((str[i]>=33 && str[i]<=47) || (str[i]>=58 && str[i]<=64)) isSymbol = true;
    }
    if(isCapital && isNumber && isSymbol) return true;
    return false;
}
int main()
{
    bool ans = strChallenge("passWord123!!!!");
    bool ans1 = strChallenge("turkey90AAA=");
    if(ans) cout << "yes" << endl;
    else cout << "no";
    if(ans1) cout << "yes";
    else cout << "no";
    return 0;
}
