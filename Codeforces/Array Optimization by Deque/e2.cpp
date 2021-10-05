// https://codeforces.com/problemset/problem/1579/E2

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

// Fenwick tree template

// BIT
vector<int> bit;

// function to get sum from 0 to ith index
int get(int i){
    int ans = 0;
    while(i){
        ans += bit[i];
        i -= (i&(-i));
    }
    return ans;
}

// function to add val to ith index
void update(int val, int i){
    while(i < bit.size()){
        bit[i] += val;
        i += (i&(-i));
    }
}

// Fenwick tree template

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++) cin>>arr[i];
        vector<int> temp(arr);
        sort(temp.begin()+1, temp.end());
        map<int, int> ele_xhtSmallest;
        int xhtSmallest = 1;
        ele_xhtSmallest[temp[1]] = xhtSmallest;
        for(int i=2; i<=n; i++){
            if(temp[i] != temp[i-1]) xhtSmallest+=1;
            ele_xhtSmallest[temp[i]] = xhtSmallest;
        }
        for(int i=1; i<=n; i++) arr[i] = ele_xhtSmallest[arr[i]];
        bit.clear(); bit.resize(xhtSmallest+1);
        ll ans = 0;
        for(int i=1; i<=n; i++){
            int lesser = get(arr[i]-1);
            int greater = i - 1 - get(arr[i]);
            ans += min(lesser, greater);
            update(1, arr[i]);
        }
        cout << ans << endl;
    }
    
    return 0;
}