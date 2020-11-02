#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int f[5000]={0};
const ll MOD = 1e9 + 7;
void solve1(vector<ll> subarr, ll n){
    ll maxele=INT_MIN;
    for(ll i=0; i<n; i++){
        if(subarr[i]>maxele){
            maxele=subarr[i];
        }
    }
    ll freq[maxele+1]={0};
    for(ll i=0; i<n; i++){
        freq[subarr[i]]++;
    }
    ll maxele2=INT_MIN, max_index=-1;
    for(ll i=1; i<=maxele; i++){
        if(freq[i]>maxele2){
            maxele2=freq[i];
            max_index=i;
        }
    }
    f[max_index]++;
}
void solve(vector<ll> arr, ll index, vector<ll> subarr){
    if(index==arr.size()){
        ll subsize=subarr.size();
        if(subsize!=0){
            solve1(subarr,subsize);
        }
    }else {
        solve(arr, index+1, subarr);
        subarr.push_back(arr[index]);
        solve(arr, index+1, subarr);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>> t;
    while(t--){
        ll n; cin>>n;
        vector<ll> arr;
        ll val;
        for(ll i=0; i<n; i++){
            cin>>val;
            arr.push_back(val);
        }
        vector<ll> b;
        solve(arr,0,b);
        for(ll i=1; i<=n; i++){
            cout << f[i] << " ";
        }
        cout << endl;
        for(ll i=0; i<5000; i++){
            f[i]=0;
        }
    }
    return 0;
}
