#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,d,w;
        cin>>m>>d>>w;
        int wx = w/__gcd(d-1,w);
        int minimum = min(m,d);
        int n= minimum/wx;
        cout << (2 * (minimum - wx) - wx * (n - 1)) * n / 2 <<endl;
    }
    return 0;
}
