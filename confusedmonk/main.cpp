#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Function to find gcd of array of numbers
int findGCD(int arr[], int n)
{
    int result = arr[0];
    for (int i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}

// Driver code
int main()
{
    int N, i;
	long long int mod = 1000000007, product = 1, output;
	cin >> N;
	int arr[N];
	for (i=0; i<N; i++){
		cin >> arr[i];
		product = (product*arr[i])%mod;
	}
	output = product;
	int gcd = findGCD(arr, N);
	for (int j=1; j<gcd; j++){
		output = (output*output)%mod;
	}
	cout << output;
}
