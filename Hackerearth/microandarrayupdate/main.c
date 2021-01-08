// https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/

#include <stdio.h>

int main(){
	int T, N, K, min;
	scanf("%d", &T);
	for (int i=0; i<T; i++){
		scanf("%d %d", &N, &K);
		int A[N];
		for (int j=0; j<N; j++){
			scanf("%d", &A[i]);
		}
		min = A[0];
		for (int k=0; k<N; k++){
			if(A[i]<min){
				min = A[i];
			}
		}
		printf("%d\n", K-min);
	}
}
