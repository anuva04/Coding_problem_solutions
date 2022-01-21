// https://codeforces.com/problemset/problem/872/B

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<int> log_table;
vector<vector<int>> min_st;
vector<int> arr;
int n;

void build(int n, int len){
    min_st = vector<vector<int>>(n, vector<int>(len+1));

    for(int i=0; i<n; i++) {
        min_st[i][0] = arr[i];
    }
    
    for(int j=1; j<=len; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            min_st[i][j] = min(min_st[i][j-1], min_st[i+(1<<(j-1))][j-1]);
        }
    }
}

int getMin(int l, int r){
    if(l>=n || r<0) return -1;
    int j = log_table[r-l+1];
    int min_in_range = min(min_st[l][j], min_st[r-(1<<j)+1][j]);
    return min_in_range;
}

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
	if(arr[0] == max_ele || arr[n-1] == max_ele) cout << max_ele << endl;
	else {
		log_table.resize(n+1);
		log_table[1] = 0;
		for(ll i=2; i<=n; i++) log_table[i] = log_table[i/2]+1;
		int len = 25;
		build(n, len);

		int ans = INT_MIN;
		for(int i=0; i<=n-2; i++){
			int min1 = getMin(0, i);
			int min2 = getMin(i+1, n-1);
			ans = max(ans, max(min1, min2));
		}
		cout << ans << endl;
	}
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