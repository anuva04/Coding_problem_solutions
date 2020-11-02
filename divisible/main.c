#include<stdio.h>

int main() {
    int N, num=0, digit, number1, number2;

    scanf("%d", &N);
    int k = N/2;
    int A[N];
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    for (int j=0; j<k; j++){
        number2 = A[j];
        while (number2 != 0){
            number1 = number2;
            number2 = number2/10;
        }
        num = num*10;
        num = num + number1;
    }
    for (int n=k; n<N; n++){
        digit = A[n]%10;
        num = num*10;
        num = num + digit;
    }
    printf("%d\n", num);
    if(num % 11 == 0){
        printf("OUI");
    }
    else {
        printf("NON");
    }
}
