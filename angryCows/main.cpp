// http://www.usaco.org/index.php?page=viewproblem2&cpid=594


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);
    int max_bales=-1;
    for(int i=0; i<n; i++){
        int index = arr[i];
        int curr_bale = 1, time = 1, left_index=i-1, right_index=i+1;
        bool up=true, down=true;
        while(1){
            bool curr_right=false, curr_left=false;
            int curr_sol_right = arr[right_index-1]+time;
            int curr_sol_left = arr[left_index+1]-time;
            while(left_index>=0 && arr[left_index]>=curr_sol_left && down){
                curr_left=true;
                left_index--;
                curr_bale++;
            }
            while(right_index<n && arr[right_index]<=curr_sol_right && up){
                curr_right=true;
                right_index++;
                curr_bale++;
            }
            if(!curr_left) down=false;
            if(!curr_right) up=false;
            if(!down && !up) break;
            time++;
        }
        max_bales = max(max_bales, curr_bale);
    }
    cout << max_bales;
    return 0;
}
