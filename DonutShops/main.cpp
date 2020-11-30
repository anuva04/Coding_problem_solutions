https://codeforces.com/problemset/problem/1373/A

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a>=c){
            cout << "-1" << " " << b <<endl;
        }else{
            float b1 = (float)c/(float)b;
            if((float)a <= b1){
                cout << "1" << " " << "-1" <<endl;
            }else {
                cout << "1" << " " << b <<endl;
            }
        }
    }
    return 0;
}
