// https://www.codechef.com/AUG21B/problems/OLYRANK

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int sum1=0, sum2=0, x;
	    for(int i=0; i<3; i++){
	        cin >> x;
	        sum1 += x;
	    }
	    for(int i=0; i<3; i++){
	        cin >> x;
	        sum2 += x;
	    }
	    if(sum1>sum2) cout << 1 << endl;
	    else cout << 2 << endl;
	}
	return 0;
}
