#include<stdio.h>
#include<math.h>
int main()
{
	long long k,n;
	scanf("%lld %lld",&n,&k);
	for(int i = 0;i < n;i++)
	{
		k = ( k * k + k) / 2 % 1000000007;
	}
	printf("%lld",k);
	
	return 0;
}