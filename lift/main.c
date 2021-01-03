// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/lift-queries/description/

#include <stdio.h>
#include<math.h>
#include<string.h>
int main()
{
int i,j,n;
scanf("%d",&n);
int a=0,b=7,c=0,d=0;
for(i=0;i<n;i++)
{
scanf("%d",&j);
c=abs(a-j);
d=abs(b-j);
if(c<d)
{
printf("A\n");
a=j;
}
else if(c>d)
{
printf("B\n");
b=j;
}
else
{
printf("A\n");
a=j;
}
}
return 0;
}
