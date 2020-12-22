// http://www.usaco.org/index.php?page=viewproblem2&cpid=760

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n; cin>>n;
    int arr[n+1], id[n+1], res[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n; i++){
        cin>>id[i];
    }
    for(int j=1; j<=3; j++){
        for(int i=1; i<=n; i++){
            int ind = arr[i];
            res[i]=id[ind];
        }
        for(int i=1; i<=n; i++){
            id[i]=res[i];
        }
    }

    for(int i=1; i<=n; i++){
        cout << res[i] << endl;
    }
    return 0;
}
