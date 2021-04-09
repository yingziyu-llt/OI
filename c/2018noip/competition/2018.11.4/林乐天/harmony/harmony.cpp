#include<stdio.h>
int main()
{
	freopen("harmony.in","r",stdin);
	freopen("harmony.out","w",stdout);
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&k,&m);
	long long  tot = n * m;
	long long  c = tot / k;
	long long  x = (1 + c) * c / 2;
	x *= k;
	x += (tot - k * c) * (c + 1);
	printf("%lld",x);
}