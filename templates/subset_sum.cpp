#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bitset<1000001> bit;

void build(vector<int>& arr){
    bit.reset();
    int n = arr.size();
    bit[0] = 1;
    for(int i=0; i<n; i++){
        bit |= (bit << arr[i]);
    }
}

bool query(int sum){
    return bit[sum];
}