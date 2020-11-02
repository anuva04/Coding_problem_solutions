
#include <stdio.h>

int main()
{
	int num,num1,num2, count = 0, isbn=0, digit, i=10;
	scanf("%d", &num);
	num1 = num;
	num2 = num;
	 while (num1 != 0)
	    {
            num1 /= 10;
            ++count;
        }
        if(count != 10)
        {
           printf("Illegal ISBN");
        }
        else
        {
            while(num2 != 0)
            {
                digit = num2%10;
                isbn = isbn + (digit*i);
                num2 /= 10;
                i--;
            }
            if(isbn%11 == 0){
                printf("Legal ISBN");
            }
            else {
                printf("Illegal ISBN");
            }
        }

}
