
#include <stdio.h>
#include <math.h>
long long int factorial(long long int n) {
   return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
long long int nPr(long long int n, long long int r) {
   return (factorial(n) / factorial(n-r));
}

long long int nCr(long long int n, long long int r) {
   return (nPr(n,r) / factorial(r));
   //return factorial(n) / factorial(r) / factorial(n-r));
}




int main(){
	int t, i;
	long int n, mod = 1000000007;
	long long int min, max;
	scanf("%d", &t);
	for (i=0; i<t; i++){
		scanf("%ld", &n);
		min = ((nCr(n,2)%mod)/(n%mod));
		min = (min*min)%mod;
		min = (min*n)%mod;
		max = (((n-1)*(n)*(2*n - 1))/6)%mod;
		printf("%lld %lld\n", min, max);
	}
}
