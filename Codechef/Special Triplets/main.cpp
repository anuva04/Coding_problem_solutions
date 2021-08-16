// https://www.codechef.com/AUG21B/problems/SPCTRIPS

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int ans = 0;
	    for(int c=1; c<=n; c++){ // no condition
	        for(int b=c; b<=n; b+=c){ // b = k*c + 0
	            for(int a=c; a<=n; a+=b){ // a = k*b + c
	                if(a%b==c && b%c==0) ans+=1;
	            }
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
