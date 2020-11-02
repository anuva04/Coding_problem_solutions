#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int arr[n+1];
	    for(int i=1; i<=n; i++){
	        cin>>arr[i];
	    }
	    int min_steps=INT_MAX, min_value=-1;
	    for(int i=1; i<=n; i++){
	        if(arr[i]<=k && k%arr[i]==0){
	            int x=(k/arr[i])-1;
	            if(x<min_steps){
	                min_steps=x;
	                min_value=arr[i];
	            }
	        }
	    }
	    cout << min_value <<endl;
	}
	return 0;
}
