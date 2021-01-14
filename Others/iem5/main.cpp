#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(int n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;

    // iterate from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }

    return n;
}
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int solve(int n){
    if(n==1) return 0;
    if(isPrime(n)) return 1;
    int x = smallestDivisor(n);
    int y = n/x;
    return ((y)+x*solve(y));
}
int main()
{
    for(int i=3000; i<=3500; i++){
    if(i==solve(i)) cout << i;
    }
    return 0;
}
