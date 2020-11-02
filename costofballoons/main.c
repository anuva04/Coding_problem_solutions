
#include <stdio.h>

int main(){
    int T, i,j, green, purple, n, a, b, counta=0, countb=0, costa, costb;
    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        scanf("%d %d", &green, &purple);
        scanf("%d", &n);
        for(j=0; j<n; j++)
        {
            scanf("%d %d", &a, &b);
            counta = counta + a;
            countb = countb + b;
        }
        costa = counta*green + countb*purple;
        costb = countb*green + counta*purple;
        if(costa>costb){
            printf("%d", costa);
        }
        else {
            printf("%d", costb);
        }
    }

}
