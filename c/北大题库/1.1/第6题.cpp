#include <stdio.h>

int main()
{
 char a;
 long long int b;
 float c;
 double d;
 scanf("%c",&a);
 scanf("%lld",&b);
 scanf("%f",&c);
 scanf("%lf",&d);
 printf("%c %lld %f %.6lf",a,b,c,d);
 return 0;
}
