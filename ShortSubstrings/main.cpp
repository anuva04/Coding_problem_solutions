// https://codeforces.com/problemset/problem/1367/A

#include <iostream>

using namespace std;

int main()
{
    int t;
    string b;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> b;
        string a;
        int len = b.size();
        if(len <= 2){
            a.append(b);
        }else{
            a.push_back(b[0]);
            for(int j=1; j<=len; j+=2){
                a.push_back(b[j]);
            }
        }
        cout << a <<endl;
    }
    return 0;
}
