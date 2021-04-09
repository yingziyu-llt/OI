#include<stdio.h>
int main()
{
 long long a,max,min;
 int i;
 scanf("%lld",&a);
 max=a;
 min=a;
 for(i=0;i<4;i++)
 {
  scanf("%lld",&a);
  if(a>max)		max=a;
  if(a<min)		min=a;
 }
 printf("%lld",max-min);
 return 0;
} 
