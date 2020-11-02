#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        int maxelement=*max_element(arr,arr+n);
        int freq[maxelement+1]={0};
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        int maxfreq=*max_element(freq,freq+maxelement+1);
        int countmaxfreq=0;
        for(int i=0; i<=maxelement; i++){
            if(freq[i]==maxfreq) countmaxfreq++;
        }
        int ans = ((n-countmaxfreq)/(maxfreq-1))-1;
        cout << ans <<endl;
    }
    return 0;
}
