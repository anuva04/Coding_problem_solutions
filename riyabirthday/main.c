
#include <stdio.h>

int main(){
	int T, i;
	long long int N, result;
	for (i=0; i<T; i++){
		scanf("%lld", &N);
		printf("*****%lld\n", N);
		result = (((2*N)-1)*N)%1000000007;
		printf("%lld\n", result);
	}
}
