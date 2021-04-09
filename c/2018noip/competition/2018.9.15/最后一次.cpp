#include<stdio.h>
#include<math.h>
bool isPrime(long long x)
{
	double maxn = sqrt(x);
	for(long long i = 2;i <= maxn;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	for(long long i = n;i > 1;i--)
	{
		if(isPrime(i)) 
		{
			printf("%lld",i);
			return 0;
		}
	} 
} 
