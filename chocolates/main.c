#include <stdio.h>

int main(){
    int d, r, x, choc=0, cir, len;
    scanf("%d", &d);
    for (int i=0; i<d; i++){
        scanf("%d %d", &r, &x);
        len = 100*x;
        cir = 2*(22.0/7)*r;
        printf("%d", cir);
        if(len>=cir){
            choc++;
        }
    }
   printf("%d", choc);
}
