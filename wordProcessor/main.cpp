#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin>>n>>k;
    string arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int char_count=0;
    for(int i=0; i<n; i++){
        int siz = arr[i].size();
        cout<<arr[i];
        char_count+=siz;
        if(i<n-1){
            int siz_next = arr[i+1].size();
            if(char_count+siz_next<=k){
                cout << " ";
            }else{
                cout<<endl;
                char_count=0;
            }
        }

    }

    return 0;
}
