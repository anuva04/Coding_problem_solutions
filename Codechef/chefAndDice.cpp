// https://www.codechef.com/APRIL21B/problems/SDICE

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin>>t;
	while(t--){
	    ll n; cin>>n;
	    vector<int> val{0,6,11,15,18,20};
	    vector<int> precompute{0,20,36,51,60,76,88,99,104};
	    if(n<=8) cout << precompute[n] <<endl;
	    else {
	        ll fours = n/4;
	        ll rem = n - (fours-1)*4;
	        ll ans = (fours-1)*44 + precompute[rem];
	        cout << ans << endl;
	    }
	}
	return 0;
}