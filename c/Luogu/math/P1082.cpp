#include<stdio.h>
void exgcd(long long a,long long b,long long &x,long long &y)
{
	if(b == 0)
	{
		x = 1;
		y = 0;
		return ;
	}
	exgcd(b,a % b,x,y);
	long long tmp = x;
	x = y;
	y = tmp - a / b *y;
	return ;
}
int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long x = 0,y = 0;
	exgcd(a,b,x,y);
	printf("%lld",(x + b) % b);
	return 0;
}