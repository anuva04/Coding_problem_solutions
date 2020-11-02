
#include <stdio.h>

int main(){
    int N, num=0, digit;
    scanf("%d", &N);
    int A[N];
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for (int j=0; j<N; j++){
        digit = A[j]%10;
        num = num*10;
        num = num + digit;
    }
    printf("%d\n", num);
    if(num%10 != 0){
        printf("No");
    }
    else {
        printf("Yes");
    }
}
