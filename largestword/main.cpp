#include <bits/stdc++.h>
using namespace std;
// bool ispresent(string s, string str, int slen, int stlen){
//     if(slen==0) return true;
//     if(stlen==0) return false;
//     if(s[slen-1]==str[stlen-1]){
//         return ispresent(s,str,slen-1,stlen-1);
//     }
//     return ispresent(s,str,slen,stlen-1);
// }
bool ispresent(char str1[], char str2[], int m, int n)
{
    // Base Cases
    if (m == 0) return true;
    if (n == 0) return false;

    // If last characters of two strings are matching
    if (str1[m-1] == str2[n-1])
        return ispresent(str1, str2, m-1, n-1);

    // If last characters are not matching
    return ispresent(str1, str2, m, n-1);
}

// Driver program to test methods of graph class
int main()
{

    return 0;
}
