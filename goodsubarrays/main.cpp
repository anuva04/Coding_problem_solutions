#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i]=s[i]-'0';
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int sum=0;
                for(int k=i; k<=j; k++){
                    sum+=arr[k];
                }
                if(sum==j-i+1) cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
