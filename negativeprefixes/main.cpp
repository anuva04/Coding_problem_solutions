#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n], lock[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0; i<n; i++){
            cin>>lock[i];
        }
        vector<int> v;
        for(int i=0; i<n; i++){
            if(lock[i]==0) v.push_back(arr[i]);
        }
        sort(v.begin(), v.end(), greater<int>());
        int i=0;
        for(int j=0; j<n; j++){
            if(lock[j]==0)
            {
                arr[j]=v[i];
                i++;
            }
        }
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
