#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);

int gcd(int a, int b);

int power(int x, unsigned int y, unsigned int m);

int modInverse(int a, int m)
{
    int g = gcd(a, m);
    if (g != 1)
        return -1;
    else
    {
        return power(a, m - 2, m);
    }
}

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
 
    return (y % 2 == 0) ? p : (x * p) % m;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}