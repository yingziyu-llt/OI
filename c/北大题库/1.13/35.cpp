#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long a;
	scanf("%lld",&a);
	int x[32]={0};
	for(int i=31;i>=0;i--)
	{
		printf("%d",(a>>i)&1);
	}
	return 0;
}
