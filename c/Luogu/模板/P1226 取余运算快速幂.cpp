#include<stdio.h>
long long num,k;
long long pd(int a)
{
	if(a==0)
	{
		return 1;
	}
	else 
	{
		long long c;
		c=pd(a/2);
		if(a%2==0)
		{
			return c*c%k;
		}
		else 
		{
			return c*c*num%k;
		}
	}
} 
int main()
{
	long long a;
	scanf("%lld%lld%lld",&num,&a,&k);
	printf("%lld^%lld mod %lld=%lld",num,a,k,pd(a));
	return 0;
} 
