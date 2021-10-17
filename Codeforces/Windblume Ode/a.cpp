// https://codeforces.com/contest/1586/problem/A

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    map<int, int> odd, even;
    ll sum = 0;
    for(int i=0; i<n; i++){ 
        cin>>arr[i]; 
        sum+=arr[i]; 
        if(arr[i]&1) odd[arr[i]] = i+1;
        else even[arr[i]] = i+1; 
    }
    if((sum%2 == 0) && (sum!=2)){
        cout << n << endl;
        for(int i=1; i<=n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    if(!isPrime(sum)){
        cout << n << endl;
        for(int i=1; i<=n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    for(auto ele : odd){
        if((sum-ele.first) != 2){
            cout << n-1 << endl;
            int idx = ele.second;
            for(int i=1; i<=n; i++){
                if(i==idx) continue;
                cout << i << " ";
            }
            cout << endl;
            return;
        }
    }
    for(auto ele : even){
        if(!isPrime(sum - ele.first)){
            cout << n-1 << endl;
            int idx = ele.second;
            for(int i=1; i<=n; i++){
                if(i==idx) continue;
                cout << i << " ";
            }
            cout << endl;
            return;
        }
    }
    for(auto ele : odd){
        for(auto ele1 : even){
            if(!isPrime(sum - ele.first - ele1.first)){
                cout << n-2 << endl;
                int idx = ele.second, idx1 = ele.second;
                for(int i=1; i<=n; i++){
                    if(i==idx || i==idx1) continue;
                    cout << i << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll test; cin>>test;
    while(test--){
        solve();
    }
    
    return 0;
}