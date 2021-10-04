// https://codeforces.com/problemset/problem/1592/B

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
        int n, x; cin>>n>>x;
        vector<int> a(n);
        vector<int> sorted(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
            sorted[i] = a[i];
        }
        sort(sorted.begin(), sorted.end());
        int left, right;
        if(n%2==1){
            left = n/2;
            right = n/2;
        }
        else {
            left = (n/2)-1;
            right = left+1;
        }
        if(left>=x){
            cout << "yes" << endl;
            continue;
        }
        bool possible = true;
        while(left>=0 && right<n){
            if(a[left] != sorted[left] && left<x && n-left-1<x){
                cout << "no" << endl;
                possible = false;
                break;
            }else{
                left -= 1;
            }
            if(a[right] != sorted[right] && right<x && n-right-1<x){
                cout << "no" << endl;
                possible = false;
                break;
            }else right += 1;

            if(n-left-1>=0 && right>=x){
                break;
            }
        }
        if(possible) cout << "yes" << endl;
    }
    
    return 0;
}