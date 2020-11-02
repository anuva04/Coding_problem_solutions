#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[11]={0};
        int val;
        for(int i=0; i<n; i++){
            cin>>val;
            arr[val]++;
        }


        int maxfreq=INT_MIN;
        for(int i=1; i<=9; i++){
            if(arr[i]>maxfreq){
                maxfreq=arr[i];
            }
        }
        int freq[maxfreq+1]={0};
        for(int i=1; i<=9; i++){
            freq[arr[i]]++;
        }


        int mode=INT_MIN, index;
        for(int i=1; i<=maxfreq; i++){

            if(freq[i]>mode){
                mode=freq[i];
                index=i;
            }
            //cout << "freq[i]=" << freq[i] << "  " << "mode=" << mode << endl;
        }
        cout<<index<<endl;
    }
    return 0;
}
