#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test;
    cin >> test;
    for(int q=0; q<test; q++){
        string s;
        cin >> s;
        int m;
        cin >> m;
        int b[m+1];
        for(int i=1; i<=m; i++){
            cin >> b[i];
        }
        char arr[m+1];
        for(int i=0; i<=m; i++){
            arr[i]='.';
        }
        sort(s.begin(), s.end());
        int end_index = s.size()-1;
        cout << "end_index: " << end_index <<endl;
        int zero_index;
        for(int j=1; j<=m; j++){
            for(int i=1; i<=m; i++){
                if(b[i]==0){
                    zero_index=i;
                    break;
                }
            }
            cout << "zero_index: " <<zero_index <<endl;
            arr[zero_index] = s[end_index];
            end_index--;
            for(int i=1; i<=m; i++){
                if(b[i]!=0 && b[i]!=-1){
                    b[i]-=abs(i-zero_index);
                }
            }
            b[zero_index]=-1;
        }
        for(int i=1; i<=m; i++){
            cout << arr[i];
        }
        cout << endl;
    }
    return 0;
}
