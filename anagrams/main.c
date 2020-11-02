
#include <stdio.h>
#include <string.h>

int main() {
	int t, lengtha=0, lengthb=0;
	char a[10000], b[10000];
	scanf("%d", &t);
	for (int i=0; i<t; i++){
		scanf("%s %s", a, b);
		lengtha = strlen(a);
		lengthb = strlen(b);
		for (int j=0; j<lengtha; j++){
			for (int k=0; k<lengthb; k++){
				if (a[j] == b[k]){
					a[j] = ".";
					b[k] = ".";
				}
			}
		}
		int count = 0;
		for(int i=0; i<lengtha; i++){
			if((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)){
				count++;
			}
		}
		for(int i=0; i<lengthb; i++){
			if((b[i] >= 65 && b[i] <= 90) || (b[i] >= 97 && b[i] <= 122)){
				count++;
			}
		}
		printf("%d\n", count);

	}
}
