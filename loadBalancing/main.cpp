#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin>>n>>b;
    int x[n], y[n];
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    int res = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int optimal_x = x[i]+1;
            int optimal_y = y[j]+1;
            int first=0, second=0, third=0, fourth=0;
            for(int k=0; k<n; k++){
                if(x[k]>optimal_x && y[k]>optimal_y) first++;
                else if(x[k]<optimal_x && y[k]>optimal_y) second++;
                else if(x[k]<optimal_x && y[k]<optimal_y) third++;
                else if(x[k]>optimal_x && y[k]<optimal_y) fourth++;
            }
            int ans = max(first, max(second, max(third, fourth)));
            res = min(res, ans);
        }
    }
    cout << res;
    return 0;
}
