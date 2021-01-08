// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/divisibe-or-2d8e196a/description/

#include<stdio.h>

int main() {
    int n,i,mid,evenDigit=0,oddDigit=0;


scanf("%d",&n);

int A[n+1];

for(i=0;i<n;i++)
scanf("%d",&A[i]);

mid=(n-1)/2;

for(i=0;i<=mid;i++)
{
while(A[i]/10!=0)
{ if(A[i]>=100000)
A[i]/=100000;

else if(A[i]>=10000)
A[i]/=10000;

else if(A[i]>=1000)
A[i]/=1000;

else if(A[i]>=100)
A[i]/=100;

else if(A[i]>=10)
A[i]/=10;

else if(A[i]>=1)
A[i]/=1;
}
if(i%2==0)
oddDigit=oddDigit+A[i];

else
evenDigit+=A[i];
}

for(i=mid+1;i<n;i++)
{

if(i%2==0)
oddDigit+=A[i]%10;

else
evenDigit+=A[i]%10;
}


if(((oddDigit>evenDigit) ? (oddDigit-evenDigit):(evenDigit-oddDigit))%11==0)
printf("OUI");

else
printf("NON");

return 0;
}