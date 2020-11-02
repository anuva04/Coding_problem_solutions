#include <stdio.h>
#include <string.h>
unsigned long long fact(int num)
{
    unsigned long long fact = 1;

    while(num > 0)
    {
        fact *= num;
		fact = fact%1000000007;
        num--;
    }

    return fact;
}
unsigned long long npr(int n, int r)
{
    return ((fact(n)%1000000007) / (fact(n-r)%1000000007))%1000000007;
}

int main(){
	int T, i, len, count, j, n;
	char str[1000000];
	scanf("%d", &T);
	for(i=0; i<T; i++){
		count = 0;
		scanf("%s", str);
		len = strlen(str);
		for(j=0; j<len; j++){
			if((str[j] == 'a') || (str[j] == 'e') || (str[j] == 'i') || (str[j] == 'o') || (str[j] == 'u')){
				count++;
			}
		}
		n = len - count + 1;
		//printf("%d\n", n);
		if(count == len){
			printf("-1\n");
		} else {
			printf("%lld\n", (((fact(len)%1000000007) - ((fact(n)%1000000007)*(fact(count)%1000000007))%1000000007)%1000000007));
		}
	}
}
