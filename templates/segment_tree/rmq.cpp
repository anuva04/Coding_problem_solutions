#include <bits/stdc++.h>
using namespace std;

vector<int> segment_tree;

int buildUtil(vector<int>& dataVector, int l, int r, int curr_idx){
    if(l==r){
        segment_tree[curr_idx] = dataVector[l];
        return segment_tree[curr_idx];
    }
    int mid = l+(r-l)/2;
    segment_tree[curr_idx] = min(buildUtil(dataVector, l, mid, curr_idx*2+1), buildUtil(dataVector, mid+1, r, curr_idx*2+2));
    return segment_tree[curr_idx];
}

void build(vector<int>& dataVector, int n){
    int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height) - 1;
    segment_tree.clear();
    segment_tree.resize(max_size);
    buildUtil(dataVector, 0, n-1, 0);
}

int getMinUtil(int ss, int se, int qs, int qe, int curr_idx){
    if(qs<=ss && qe>=se) return segment_tree[curr_idx];
    if(se<qs || ss> qe) return INT_MAX;
    int mid = ss + (se-ss)/2;
    return min(getMinUtil(ss, mid, qs, qe, 2*curr_idx+1), getMinUtil(mid+1, se, qs, qe, 2*curr_idx+2));
}

int getMin(int n, int qs, int qe){
    if(qs<0 || qe>=n || qs>qe) return -1;
    return getMinUtil(0, n-1, qs, qe, 0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    build(arr, n);
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        cout << getMin(n, a, b) << endl;
    }
}