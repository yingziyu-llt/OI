#include<stdio.h>
int main()
{
	int i,k;
	long long c,a,b;
	scanf("%d",&k);
	a=1;
	b=1;
	c=1;
	for(i=3;i<=k;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}  
	printf("%lld",c);
	return 0;
}
