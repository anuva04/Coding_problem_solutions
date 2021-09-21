// https://codeforces.com/contest/1574/problem/B

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
        int a, b, c, m;
        cin>>a>>b>>c>>m;
        ll max_pairs = 0;
        if(a!=0)max_pairs += (a-1);
        if(b!=0)max_pairs += (b-1);
        if(c!=0)max_pairs += (c-1);
        ll max_freq = max(a, max(b,c));
        vector<int> abc = {a,b,c};
        sort(abc.begin(), abc.end());
        ll min_pairs = abc[2] - abc[1] - abc[0] - 1;
        // cout << max_pairs << " " << min_pairs << endl;
        if((m>=min_pairs) && (m<=max_pairs)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}