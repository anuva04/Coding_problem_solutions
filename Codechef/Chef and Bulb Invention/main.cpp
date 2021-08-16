// https://www.codechef.com/AUG21B/problems/CHFINVNT

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin>>t;
	while(t--){
	    ll n, p , k;
	    cin>>n>>p>>k;
	    
	    ll num_total_muls = ((n-1)/k)+1;
	    
	    ll mul_before_n = (n/k)*k;
	    ll mul_before_p = (p/k)*k;
	    
	    ll n_excess = ((n-1)%k)+1;
	    ll p_excess = p%k;
	    ll ans;
	    
	    if(p_excess >= n_excess){
	        ans = num_total_muls*n_excess + abs(n_excess-p_excess)*(num_total_muls-1);
	    } else {
	        ans = p_excess*num_total_muls;
	    }
	    ll rem = p/k + 1;
	    cout << ans+rem << endl;
	}
	return 0;
}
