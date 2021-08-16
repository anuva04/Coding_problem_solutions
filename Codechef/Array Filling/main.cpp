// https://www.codechef.com/AUG21B/problems/ARRFILL

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t; cin>>t;
	
	while(t--){
	    ll m,n;
	    cin>>n>>m;
	    vector<pair<ll, ll> > y_x;
	    
	    for(int i=0; i<m; i++){
	        ll x, y;
	        cin>>x>>y;
	        y_x.push_back({x,y});
	    }
	    sort(y_x.begin(), y_x.end(), greater<pair<int,int>>());
	    ll rem_idx = n;
	    ll sum = 0;
	    ll curr_lcm = 1;
	    
	    for(ll i=0; i<y_x.size(); i++){
	        if(rem_idx == 0) break;
	       ll gcd = __gcd(curr_lcm, y_x[i].second);
	       curr_lcm = (curr_lcm/gcd)*y_x[i].second;
	        ll divisible = n/curr_lcm;
	        sum += (rem_idx-divisible)*y_x[i].first;
	        rem_idx = divisible;
	    }
	    
	    cout << sum << endl;
	}
	return 0;
}
