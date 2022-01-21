// https://codeforces.com/problemset/problem/872/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> arr;
int n;

void solve(){
	int k; cin>>n>>k;
	arr.resize(n);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int max_ele = *max_element(arr.begin(), arr.end());
	if(k == 1){
		cout << *min_element(arr.begin(), arr.end()) << endl;
		return;
	}
	if(k>=3){
		cout << max_ele << endl;
		return;
	}
	cout << max(arr[0], arr[n-1]) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}