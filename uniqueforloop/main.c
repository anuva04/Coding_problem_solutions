#include<stdio.h>
int main(){
    int a,s;
   for(    scanf("%d",&a)  ,  s=0     ;   a!=0     ;    s=s*10+(a%10)   ,   a=a/10)  ;
    printf("%d",s);
     }
