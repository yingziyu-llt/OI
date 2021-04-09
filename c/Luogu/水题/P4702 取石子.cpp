#include<stdio.h>
int main()
{
	long long n,b,sum=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&b);
		sum+=b;
	}
	if(sum%2==0)
	{
		printf("Bob");
	}
	else
	{
		printf("Alice");
	}
	return 0;
}
