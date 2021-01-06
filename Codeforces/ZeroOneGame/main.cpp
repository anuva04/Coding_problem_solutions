// https://codeforces.com/problemset/problem/1373/B

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        int cnt = 0;

        bool win = false;
        while(s.size()>0){
            int sizes = s.size();
            int index=-1;
            for(int j=0; j<sizes-1; j++){
                if(s[j]!=s[j+1]){
                    index=j;
                    break;
                }
            }
            if(index!=-1){
                s.erase(index,2);
                win = !win;
            }else{
                break;
            }
        }
        if(win == false){
            cout << "NET" <<endl;
        }else{
            cout << "DA" <<endl;
        }
    }
    return 0;
}
