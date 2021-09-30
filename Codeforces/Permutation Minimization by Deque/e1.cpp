// https://codeforces.com/problemset/problem/1579/E1

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ll test; cin>>test;
    while(test--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        deque<int> d;
        d.push_back(arr[0]);
        for(int i=1; i<n; i++){
            if(d.front()>=arr[i]) d.push_front(arr[i]);
            else d.push_back(arr[i]);
        }
        for(int i=0; i<n; i++){
            cout << d.front() << " ";
            d.pop_front();
        }
        cout << endl;
    }
    
    return 0;
}