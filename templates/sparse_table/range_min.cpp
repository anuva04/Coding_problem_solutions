#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

// function to build sparse table
vector<vector<int>> build(vector<int>& dataVector){
    int N = dataVector.size();
    vector<vector<int>> sparse_table(N, vector<int>(log2(N)+1));
    for(int i=0; i<N; i++){
        sparse_table[i][0] = i;
    }
    for(int j=1; (1<<j)<=N; j++){
        for(int i=0; i+(1<<j)<=N;  i++){
            if(dataVector[sparse_table[i][j-1]] < dataVector[sparse_table[i+(1<<(j-1))][j-1]]) sparse_table[i][j] = sparse_table[i][j-1];
            else sparse_table[i][j] = sparse_table[i+(1<<(j-1))][j-1];
        }
    }
    return sparse_table;
}

// function to query from sparse table (min in range L to R)
int query(vector<int>& dataVector, int l, int r, vector<vector<int>>& sparse_table){
    int len = r-l+1;
    int k = log2(len);
    if(dataVector[sparse_table[l][k]] <= dataVector[sparse_table[r-(1<<k)+1][k]]) return dataVector[sparse_table[l][k]];
    return dataVector[sparse_table[r-(1<<k)+1][k]];
}

int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    auto sparse_table = build(arr);
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout << query(arr, l, r, sparse_table) << endl;
    }
}