#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int s=0; s<t; s++){
        int m;
        cin >> m;
        int n = m;
        int a[m][n];

        int value=1, k=0, l=0;
        while(k<m && l<n){
            for(int i=l; i<n; ++i){
                a[k][i] = value++;
            }
            k++;
            for(int i=k; i<m; ++i){
                a[i][n-1] = value++;
            }
            n--;
            if (k < m){
                for (int i = n-1; i >= l; --i)
                    a[m-1][i] = value++;
                m--;
            }

            if (l < n){
                for (int i = m-1; i >= k; --i)
                     a[i][l] = value++;
                l++;
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}
