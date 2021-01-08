// https://www.codechef.com/LTIME88B/problems/ROOTTREE
// Partial Solution

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    vector<pair<int,int> > vec;
	    int u,v;
	    int cnt=0;
	    for(int i=0; i<n-1; i++){
	        cin>>u>>v;
	        vec.push_back(make_pair(u,v));
	        if(v==1) cnt+=1;
	    }
	    if(cnt<=1) cout << 0 << endl;
	    else cout << cnt-1 << endl;
	}
	return 0;
}
