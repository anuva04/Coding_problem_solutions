
#include <stdio.h>

int main(){
	int a, flag = 0;
	long int n, i, j;
	scanf("%ld", &n);
	int arr[n];
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(i=0; i<n; i++){
		a = arr[i];
		for(j=i+1; j<n; j++){
			if(a > arr[j]){
				flag = 1;
			}
			else {
				flag = -1;
				break;
			}
		}
		if (flag == 1){
			printf("%d ", a);
		}
	}
}
