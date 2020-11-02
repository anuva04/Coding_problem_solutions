#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int start_index = 1, end_index=n;
    int y;
    char ans = 'A';
    while(1){
        y=(start_index+end_index)/2;
        cout << 1 << endl;
        cin >> ans;
        if(ans == 'E'){
            return 0;
        }else if(ans == 'G'){
            continue;
        }else if(ans == 'L'){
            cout << y << endl;
            cin >> ans;
            if(ans=='E'){
                return 0;
            }else if(ans=='G'){
                start_index=y+1;
            }else if(ans=='L'){
                end_index=y-1;
            }
        }
    }
}
