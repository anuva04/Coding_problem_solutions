#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n],b[n];
        int amin=INT_MAX, bmin=INT_MAX;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]<amin) amin=a[i];
        }
        for(int i=0; i<n; i++){
            cin>>b[i];
            if(b[i]<bmin) bmin=b[i];
        }
        long long countt=0;
        for(int i=0; i<n; i++){
            int diffa=a[i]-amin;
            int diffb=b[i]-bmin;
            int maxx=(diffa>diffb)?diffa:diffb;
            countt=countt+maxx;
        }
        cout << countt << endl;
    }
    return 0;
}
