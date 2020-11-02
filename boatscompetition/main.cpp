#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int w[n];
        for(int i=0; i<n; i++){
            cin>>w[i];
        }
        sort(w, w+n);
        int maxx=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int sum=w[i]+w[j];
                int left=i+1;
                int right=j-1;
                int countt=0;
                while(left<right){
                    if(w[left]+w[right]==sum){
                        countt++;
                        left++;
                        right--;
                    }
                    else if(w[left]+w[right]<sum) left++;
                    else right--;
                }
                if(countt+1>maxx) maxx=countt+1;
            }
        }
    }
    return 0;
}
