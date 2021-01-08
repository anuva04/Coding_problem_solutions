// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/divisible-or-not-81b86ad7/description/

#include <stdio.h>

int main(){
    int N, num, digit;
    scanf("%d", &N);
    int A[N];
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    num = A[N-1]%10;
    if(num == 0){
        printf("Yes");
    }
    else {
        printf("No");
    }
}