#include<stdio.h>
long long pow(long long a,long long b,long long mod)
{
	long long res = 1;
	while(b)
	{
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}
int main()
{
	long long a,b,mod;
	scanf("%lld %lld %lld",&a,&b,&mod);
	printf("%lld^%lld mod %lld=%lld",a,b,mod,pow(a,b,mod));
	return 0;
}