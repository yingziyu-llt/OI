#include<stdio.h>
#include<math.h>
int main()
{
 double a,b,c,p,temp;
 scanf("%lf %lf %lf",&a,&b,&c);
 if((a+b>c)&&(a+c>b)&&(b+c>a))
 {
  p=(a+b+c)/2;
  temp=sqrt(p*(p-a)*(p-b)*(p-c));
  printf("%.3lf",temp);
 }
 else                           printf("No");
 return 0;
}
