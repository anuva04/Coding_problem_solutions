// https://www.spoj.com/problems/PTRI2/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 1000000000;

vector<bool> is_prime;
const int maxn = 1e8 + 1;

vector<int> primes;
vector<vector<int>> triangle;

void init(){
    is_prime.assign(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i <= maxn; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=maxn; j+=i) is_prime[j] = false;
        }
    }
    primes.push_back(2);
    for(int i=3; i<=maxn; i+=2){
        if(is_prime[i]) primes.push_back(i);
    }

    int len = 1, i = 0;
    while(i<primes.size()){
        int curr_len = len;
        len++;
        triangle.push_back({});
        while(curr_len && i<primes.size()){
            triangle.back().push_back(primes[i]);
            i++;
            curr_len--;
        }
    }
}

void solve(){
    int n; cin>>n;
    if(!is_prime[n]) {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = triangle.size()-1, m;
    while(l<r){
        m = (l+r+1)/2;
        if(triangle[m][0]>n) r = m-1;
        else l = m;
    }
    int i = l;
    l = 0, r = triangle[i].size()-1;
    while(l < r){
        m = (l+r+1)/2;
        if(triangle[i][m] > n) r = m-1;
        else l = m;
    }
    cout << i+1 << ' ' << l+1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    init();

    ll test; cin>>test;
    while(test--){
        solve();
    }
    // for(ll t=1; t<=test; t++){
    //     cout << "Case " << t << ": ";
    //     solve();
    // }
    
    return 0;
}