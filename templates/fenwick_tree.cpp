#include <bits/stdc++.h>
using namespace std;

// fenwick tree template

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