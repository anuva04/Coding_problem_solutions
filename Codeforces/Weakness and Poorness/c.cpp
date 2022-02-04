// https://codeforces.com/problemset/problem/578/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

double kadane(vector<double>& a){
    double mx = 0, curr_mx = 0;
    for(auto ele : a){
        curr_mx += ele;
        mx = max(curr_mx, mx);
        if(curr_mx < 0) curr_mx = 0;
    }
    return mx;
}

double cost_function(double x, vector<int>& arr){
    vector<double> a(arr.size());
    for(int i=0; i<arr.size(); i++) a[i] = arr[i] - x;
    double pos = kadane(a);
    for(int i=0; i<arr.size(); i++) a[i] *= -1;
    double neg = kadane(a);
    return max(pos, neg);
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];

    double left = *min_element(arr.begin(), arr.end());
    double right = *max_element(arr.begin(), arr.end());
    int turns = 200;

    double ans = INT_MAX;
    while(turns--){
        double mid1 = left + (right-left)/3;
        double mid2 = right - (right-left)/3;
        double ans1 = cost_function(mid1, arr);
        double ans2 = cost_function(mid2, arr);
        ans = min(ans, min(ans1, ans2));
        if(ans1 < ans2) right = mid2; else left = mid1;
    }
    cout << fixed << setprecision(15) << ans << endl;
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