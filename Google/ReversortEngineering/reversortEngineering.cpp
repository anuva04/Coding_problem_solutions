// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
// This is brute-force approach

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){

        int n, c;
        cin>>n>>c;

        if(c<n-1 || c>n*(n+1)/2 - 1){
            cout << "Case #" << tt << ": ";
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int idx[n], ans[n];
        for(int i=0; i<n; i++) idx[i]=i;
        for(int i=0; i<n-1; i++){
            int elements_left_to_process = n-2-i;
            int max_arr_size_to_reverse = n-i;
            int arr_size_to_reverse = min(max_arr_size_to_reverse, c - elements_left_to_process);
            c -= arr_size_to_reverse;
            reverse(idx+i, idx+i+arr_size_to_reverse);
            ans[idx[i]] = i+1;
        }
        ans[idx[n-1]] = n;
        cout << "Case #" << tt << ": ";
        for(int i=0; i<n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}