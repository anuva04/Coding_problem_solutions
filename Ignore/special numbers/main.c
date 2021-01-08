#include <stdio.h>
#include <stdlib.h>
int main(){
    int N, max=0, n, sum=0, i, j, k, m;
    scanf("%d", &N);
    int A[N];
    for (i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
   /* k=1;
    j=0;
    while (k<N){
        for(m=0; m<k; m++){
            max = max + A[j];
            j++;
        }
        k++;
    }*/
    for(i=0; i<N; i++){
        j = i;
        k = 1;
        while (k<N){
            for(m=0; m<k; m++){
                sum = sum + A[j];
                printf("%d ", sum);
                j++;
            }
            k++;
        }
        if (sum > max){
            max = sum;
        }
    }
    printf("*******%d*******", max);
}
