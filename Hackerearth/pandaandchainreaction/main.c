// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/

#include <stdio.h>

int main(){
	int T, i;
	long long int j, N, X, particle;
	scanf("%d", &T);
	for (i=0; i<T; i++){
		scanf("%d %d", &N, &X);
		particle = X;
		for (j=1; j<=N; j++){
			particle = particle*j;
			printf("****%lld****\n", particle);
		}
		printf("%lld\n", particle);
	}
}
