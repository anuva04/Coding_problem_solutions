// https://codeforces.com/problemset/problem/380/C

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

vector<vector<int>> segment_tree;
// segment_tree[curr_idx][0] = correct sequence length
// segment_tree[curr_idx][1] = number of left brackets
// segment_tree[curr_idx][2] = number of right brackets

vector<int> buildUtil(string& dataVector, int l, int r, int curr_idx){
    if(l==r){
        segment_tree[curr_idx][0] = 0;
        if(dataVector[l] == '('){
            segment_tree[curr_idx][1] = 1;
            segment_tree[curr_idx][2] = 0;
        } else{
            segment_tree[curr_idx][1] = 0;
            segment_tree[curr_idx][2] = 1;
        }
        return segment_tree[curr_idx];
    }
    int mid = l+(r-l)/2;
    vector<int> left = buildUtil(dataVector, l, mid, curr_idx*2+1);
    vector<int> right = buildUtil(dataVector, mid+1, r, curr_idx*2+2);
    int new_seq = min(left[1], right[2]);
    segment_tree[curr_idx][0] = left[0]+right[0]+2*new_seq;
    segment_tree[curr_idx][1] = left[1]-new_seq+right[1];
    segment_tree[curr_idx][2] = left[2]+right[2]-new_seq;
    return segment_tree[curr_idx];
}

void build(string& dataVector, int n){
    int height = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, height) - 1;
    segment_tree.clear();
    segment_tree.resize(max_size);
    for(int i=0; i<max_size; i++){
        segment_tree[i].resize(3);
    }
    buildUtil(dataVector, 0, n-1, 0);
}

vector<int> getUtil(int ss, int se, int qs, int qe, int curr_idx){
    if(qs<=ss && qe>=se) return segment_tree[curr_idx];
    if(se<qs || ss> qe) return {0,0,0};
    int mid = ss + (se-ss)/2;
    vector<int> left = getUtil(ss, mid, qs, qe, 2*curr_idx+1);
    vector<int> right = getUtil(mid+1, se, qs, qe, 2*curr_idx+2);
    vector<int> ans(3);
    ans[0] = left[0]+right[0];
    int new_seq = min(left[1], right[2]);
    ans[0] += (new_seq*2);
    ans[1] = left[1]-new_seq+right[1];
    ans[2] = left[2]+right[2]-new_seq;
    return ans;
}

int get(int n, int qs, int qe){
    if(qs<0 || qe>=n || qs>qe) return -1;
    vector<int> ans = getUtil(0, n-1, qs, qe, 0);
    return ans[0];
}

void solve(){
    string s; cin>>s;
    int n = s.size();
    build(s, n);
    // cout << segment_tree.size() << endl;
    // for(int i=0; i<segment_tree.size(); i++){
    //     cout << segment_tree[i][0] << " " << segment_tree[i][1] << " " << segment_tree[i][2] << endl;
    // }
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        cout << get(n, l-1, r-1) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll test; cin>>test;
    // while(test--){
        solve();
    // }
    // for(int t=1; t<=test; t++){
    //     cout << "Case #" << t << ": ";
    //     solve();
    // }
    
    return 0;
}