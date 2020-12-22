// https://www.codechef.com/problems/CHRL2

#include <iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        getline(cin, s);
        int len = s.length();
        int count = 0;
        int j=0;
        while(j<len-1){
            if(s[j] != s[j+1]){
                count++;
                j = j+2;
            }else{
                j=j+1;
            }
        }
        cout << count <<endl;
    }
}
