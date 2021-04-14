// https://www.codechef.com/APRIL21B/problems/KAVGMAT

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


ll solve2(vector<vector<ll>>& mat, ll rows, ll cols, vector<vector<ll>>& prefix, ll k){
	ll ans = 0;
    for(ll i=0; i<rows; i++){
        for(ll j=0; j<cols; j++){
            if(mat[i][j] >= k){
                ans += (min(rows-i, cols-j));
                continue;
            }
            ll max_rows = rows-i;
            ll max_cols = cols-j;
            ll max_size = min(max_cols, max_rows);
            ll maxx = max_size;
            ll min_size = 1;
            ll sz;
            while(min_size <= max_size){
                sz = min_size + (max_size-min_size)/2;
                ll cur_i = i+sz-1;
                ll cur_j = j+sz-1;
                ll sum = prefix[cur_i][cur_j];
                if(i-1 >= 0) sum -= prefix[i-1][cur_j];
                if(j-1 >= 0) sum -=  prefix[cur_i][j-1];
                if(i-1>=0 && j-1>=0) sum += prefix[i-1][j-1];
                if(sum == k*sz*sz){
                    break;
                }
                else if(sum < k*sz*sz){
                    min_size = sz+1;
                } else {
                    max_size = sz-1;
                }
            }
            //cout << endl;
            ll cur_i = i+sz-1;
            ll cur_j = j+sz-1;
            ll sum = prefix[cur_i][cur_j];
            if(i-1 >= 0) sum -= prefix[i-1][cur_j];
            if(j-1 >= 0) sum -=  prefix[cur_i][j-1];
            if(i-1>=0 && j-1>=0) sum += prefix[i-1][j-1];
            if(sum >= k*sz*sz){
                //cout << i << " " << j << " " << sz << endl;
                //cout << (maxx-sz+1) << endl;
                ans += (maxx-sz+1);
                if(cur_i-1>=0 && cur_j-1>=0 && sz-1>0){
                    sz = sz-1;
                    cur_i = i+sz-1;
                    cur_j = j+sz-1;
                    sum = prefix[cur_i][cur_j];
                    if(i-1 >= 0) sum -= prefix[i-1][cur_j];
                    if(j-1 >= 0) sum -=  prefix[cur_i][j-1];
                    if(i-1>=0 && j-1>=0) sum += prefix[i-1][j-1];
                    if(sum >= k*sz*sz){
                        //cout << "sz-1 -> " << i << " " << j << " " << sz << endl;
                        ans += 1;
                    }
                }
            } else if(cur_i+1<rows && cur_j+1<cols){
                sz = sz+1;
                cur_i = i+sz-1;
                cur_j = j+sz-1;
                sum = prefix[cur_i][cur_j];
                if(i-1 >= 0) sum -= prefix[i-1][cur_j];
                if(j-1 >= 0) sum -=  prefix[cur_i][j-1];
                if(i-1>=0 && j-1>=0) sum += prefix[i-1][j-1];
                if(sum >= k*sz*sz){
                    //cout << "sz+1 -> " << i << " " << j << " " << sz << endl;
                    ans += (maxx-sz+1);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int t; cin>>t;
    while(t--){
        ll rows, cols, k;
        cin>>rows>>cols>>k;
        vector<vector<ll>> mat(rows, vector<ll>(cols));
        for(ll i=0; i<rows; i++){
            for(ll j=0; j<cols; j++){
                cin>>mat[i][j];
            }
        }
        vector<vector<ll> > prefix(rows, vector<ll>(cols));
        for(ll i=0; i<rows; i++){
            for(ll j=0; j<cols; j++){
                prefix[i][j] += mat[i][j];
                if(i-1>=0 && j-1>=0) prefix[i][j] -= prefix[i-1][j-1];
                if(i-1>=0) prefix[i][j] += prefix[i-1][j];
                if(j-1>=0) prefix[i][j] += prefix[i][j-1];
            }
        }
		ll ans;
		ans = solve2(mat, rows, cols, prefix, k);
		cout << ans << endl;
        
    }
    return 0;
}