// https://www.codechef.com/AUG21B/problems/PROBDIFF

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int arr[4];
	    set<int> s;
	    for(int i=0; i<4; i++){ 
	        cin>>arr[i];
	        s.insert(arr[i]);
	    }
	    if(s.size() == 4 || s.size()==3) cout << 2 << endl;
	    else if(s.size() == 2){
	        sort(arr, arr+4);
	        if((arr[0]==arr[1] && arr[1]==arr[2])||(arr[1]==arr[2] && arr[2]==arr[3])) cout << 1 << endl;
	        else cout << 2 << endl;
	    } else cout << 0 << endl;
	}
	return 0;
}
