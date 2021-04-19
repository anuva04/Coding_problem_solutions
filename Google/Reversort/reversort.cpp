// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> v1, vector<int> v2){
    for(int i=0; i<v1.size(); i++){
        if(v1[i]!=v2[i]) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    for(int test=1; test<=t; test++){
        int n; cin>>n;
        vector<int> v;
        vector<int> sortedV;
        int cost = 0;
        for(int i=0; i<n; i++){
            int val;
            cin>>val;
            v.push_back(val);
            sortedV.push_back(val);
        }
        sort(sortedV.begin(), sortedV.end());
        for(int i=0; i<n-1; i++){
            int minn = v[i];
            int min_index = i;
            for(int k=i; k<n; k++){
                if(v[k] < minn){
                    minn = v[k];
                    min_index = k;
                }
            }
            cost += (min_index-i+1);
            int l = i;
            int r = min_index;
            while(l<=r){
                swap(v[l], v[r]);
                l++;
                r--;
            }
            if(isSorted(v, sortedV)){
                cost += (n-i-2);
                break;
            }
        }
        cout << "Case #" << test << ": " << cost << endl;

    }
}