// https://codeforces.com/contest/1526/problem/C1
// and
// https://codeforces.com/contest/1526/problem/C2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll cnt=0, sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
        cnt += 1;
        pq.push(a[i]);
        if(sum<0){
            while(sum<0){
                sum -= pq.top();
                pq.pop();
                cnt -= 1;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}