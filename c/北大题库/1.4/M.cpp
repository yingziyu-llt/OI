#include<stdio.h>
#include<math.h>
int main()
{
	long long a,c;
	double b;
	scanf("%lld",&a);
	b=sqrt(a);
	c=(int)b;
	if(c*c==a)	printf("%lld",c);
	else 		printf("%.2lf",b);
	return 0;
}
