#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int a=0; a<t; a++){
        int n, p;
        cin >> n >> p;
        int mat[n+1][n+1];
        int x=-1, prevx;
        for(int i=1; i<=n; i++){
            for(int j=n; j>=1; j--){
                cout << 1 << " " << i << " " << 1 << " " << i << " " << j << endl;
                cin >> x;
                if(x==j){
                    for(int k=1; k<=j; k++){
                        mat[i][k]=1;
                    }
                    break;
                } else if(x==0){
                    for(int k=1; k<=j; k++){
                        mat[i][k]=0;
                    }
                    break;
                }else{
                    cout << 1 << " " << i << " " << 1 << " " << i << " " << j-1 << endl;
                    cin >> prevx;
                    if(prevx==x){
                        mat[i][j]=0;
                    }else{
                        mat[i][j]=1;
                    }
                }
            }
        }
        cout << 2 <<endl;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << mat[i][j] << " ";
            }
            cout <<endl;
        }
        cin >> x;
        if(x==-1){
            return 0;
        }
    }
}
