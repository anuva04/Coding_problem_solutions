#include <bits/stdc++.h>
using namespace std;

vector<int> segment_tree;
vector<int> lazy;

void buildUtil(vector<int> dataVector, int ss, int se, int curr_idx){
    if(ss > se) return;
    if(ss == se){
        segment_tree[curr_idx] = dataVector[ss];
        return;
    }
    int mid = (ss+se)>>1;
    buildUtil(dataVector, ss, mid, 2*curr_idx+1);
    buildUtil(dataVector, mid+1, se, 2*curr_idx+2);
    segment_tree[curr_idx] = segment_tree[2*curr_idx+1] + segment_tree[2*curr_idx+2];
}

void build(vector<int> dataVector, int n){
    int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height) - 1;
    segment_tree.clear();
    segment_tree.resize(max_size);
    lazy.clear();
    lazy.resize(max_size);
    for(int i=0; i<max_size; i++) lazy[i] = 0;
    buildUtil(dataVector, 0, n-1, 0);
}

void updateRangeUtil(int curr_idx, int ss, int se, int us, int ue, int diff){
    if(lazy[curr_idx]!=0){
        segment_tree[curr_idx] += (se-ss+1)*lazy[curr_idx];
        if(ss != se){
            lazy[2*curr_idx+1] += lazy[curr_idx];
            lazy[2*curr_idx+2] += lazy[curr_idx];
        }
        lazy[curr_idx] = 0;
    }
    if(ss>se || ss>ue || se<us) return;
    if(ss>=us && se<=ue){
        segment_tree[curr_idx] += (ss-se+1)*diff;
        if(ss != se){
            lazy[2*curr_idx+1] += diff;
            lazy[2*curr_idx+2] += diff;
        }
        return;
    }
    int mid = (ss+se)>>1;
    updateRangeUtil(2*curr_idx+1, ss, mid, us, ue, diff);
    updateRangeUtil(2*curr_idx+2, mid+1, se, us, ue, diff);
    segment_tree[curr_idx] = segment_tree[2*curr_idx+1] + segment_tree[2*curr_idx+2];
}

void updateRange(int n, int us, int ue, int diff){
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getUtil(int ss, int se, int qs, int qe, int curr_idx){
    if(lazy[curr_idx] != 0){
        segment_tree[curr_idx] += (se-ss+1)*lazy[curr_idx];
        if(ss != se){
            lazy[2*curr_idx+1] += lazy[curr_idx];
            lazy[2*curr_idx+2] += lazy[curr_idx];
        }
        lazy[curr_idx] = 0;
    }
    if(ss>se || ss>qe || se<qs) return 0;
    if(ss>=qs && se<=qe) return segment_tree[curr_idx];
    int mid = (ss+se)>>1;
    return getUtil(ss, mid, qs, qe, 2*curr_idx+1)+getUtil(mid+1, se, qs, qe, 2*curr_idx+2);
}

int get(int n, int qs, int qe){
    if(qs<0 || qe>n-1 || qs>qe) return -1;
    return getUtil(0, n-1, qs, qe, 0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    build(arr, n);
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int type, a, b, diff;
        cin>>type;
        if(type==1) cin>>a>>b;
        else cin>>a>>b>>diff;
        if(type==1) cout << get(n, a, b) << endl;
        else updateRange(n, a, b, diff);
    }
}