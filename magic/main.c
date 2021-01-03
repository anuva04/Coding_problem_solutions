// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/its-magic/

#include <stdio.h>

int main(){
    int N, sum=0, sum1, num1=0, num2, index=-1;
    scanf("%d", &N);
    int arr[N], arr1[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<N; i++){
        sum = sum + arr[i];
    }
    for (int j=0; j<N; j++){
        sum1 = sum - arr[j];
        if(sum1%7 == 0){
            num2 = num1;
            num1 = arr[j];
            if(num1<num2){
                num1 = num2;
                index = j;
            }
        }
    }
    printf("%d", index);
}

