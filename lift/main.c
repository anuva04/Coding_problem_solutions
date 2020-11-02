#include <stdio.h>

int main(){
    int T, N, a, b;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        a = N;
        b = 7-N;
        if(a<=b){
            printf("A\n");
        }
        else {
            printf("B\n");
        }
    }
}
