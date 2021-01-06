// https://codeforces.com/problemset/problem/1400/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        char arr[n];
        int j=0;
        for(int i=0; i<2*n-1; i=i+2){
            arr[j]=s[i];
            j++;
        }
        for(int i=0; i<n; i++){
            cout<<arr[i];
        }
        cout << endl;
    }
    return 0;
}
