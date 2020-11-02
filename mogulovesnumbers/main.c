#include <stdio.h>

int main(){
	int Q, L, R, i, j, k, div, flag, count;
	scanf("%d", &Q);
	for(i=0; i<Q; i++){
		scanf("%d %d", &L, &R);

		if (L>R){
			count = 0;

			for(j=R; j<=L; j++){
				div = 0;
				for(k=1; k<=j; k++){
					if(j%k == 0){
						div++;
					}
				}

				if (div == 2){
					count++;
				}
			}
			printf("%d\n", count);
		}
		else {

			count = 0;
			for(j=L; j<=R; j++){
				div = 0;
				for(k=1; k<=j; k++){
					if(j%k == 0){
						div++;
					}
				}

				if (div == 2){
					count++;
				}
			}
			printf("%d\n", count);
		}
	}
}
