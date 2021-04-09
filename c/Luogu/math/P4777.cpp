#include<stdio.h>
const int N = 110000;
long long a[N],m[N],n;
long long exgcd(long long a,long long b,int &x,long long &y)
{
	long long gcd;
	if(b != 0)
		gcd = exgcd(b,a % b,x,y);
	long long tmp;
	tmp = x;
	x = y;
	y = tmp - a / b * y;
	return b == 0 ? a : gcd;
}
long long mul(long long a,long long b,long long mod)
{
	long long res = 0;
	while(b)
	{
		if(b & 1)
			ans = (ans + a % mod) % mod;
		a = ((a % mod) + (a % mod)) % mod;
		b >>= 1;
	}
	return res;
}
long long excrt()
{
	long long x,y,k;
	long long M = m[1],ans = a[1];
	for(int i = 2;i <= n;i++)
	{
		
	}
}
int main()
{

}