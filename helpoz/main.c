// https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/a-simple-task/
// Partial Solution

#include <stdio.h>
int main(){
	int M, i;

	scanf("%d", &M);
	long int arr[M], max, K, j, modulo=0;
	for (i=0; i<M; i++){
		scanf("%ld", &arr[i]);
	}
	max = arr[0];
	for(i=0; i<M; i++){
		if(arr[i]>max){
			max = arr[i];
		}
	}
	for (K=2; K<=max; K++){

		//modulo = arr[0]%K;
		for(i=1; i<M; i++){
			if(arr[i]%K != arr[i-1]%K){
                modulo = 1;
			}
		}
		if (modulo == 0){
            printf("%ld ", K);
        }
	}
}

