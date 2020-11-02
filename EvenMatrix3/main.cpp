#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int s=0; s<t; s++){
        int m;
        cin >> m;
        int arr[m][m];
        int val=1;
        for(int i=0; i<m; i++){
            if(i%2 == 0){
                for (int j = 0; j < m; j++){
                    arr[i][j] = val;
                    val++;
                }
            } else {
                for (int j = m-1; j >= 0; j--){
                    arr[i][j] = val;
                    val++;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
