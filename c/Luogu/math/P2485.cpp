#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
long long fastpow(long long a,long long b,long long mod)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans % mod) * (a % mod) % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
	long long gcd;
	if(b != 0)
		gcd = exgcd(b,a % b,x,y);
	if(b == 0)
	{
		x = 1,y = 0;
		return a;
	}
	long long tmp = x;
	x = y;
	y = tmp - a / b * y;
	return gcd;
}
long long BSGS(long long a, long long b, long long p)
{
	map<long, long> hash;
	hash.clear();
	b %= p;
	int t = (int)sqrt(p) + 1;
	for (int j = 0; j < t; j++)
	{
		int val = (long long)b * fastpow(a, j, p) % p;
		hash[val] = j;
	}
	a = fastpow(a, t, p);
	if (a == 0)
	{
		if (b == 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	for (int i = 0; i <= t; i++)
	{
		int val = fastpow(a, i, p);
		int j = hash.find(val) == hash.end() ? -1 : hash[val];
		if (j >= 0 && i * t - j >= 0)
		{
			return i * t - j;
		}
	}
	return -1;
}
int main()
{
	long long t,k,y,z,p;
	scanf("%lld %lld",&t,&k);
	for(int i = 0;i < t;i++)
	{
		if(k == 1)
		{
			scanf("%lld%lld%lld",&y,&z,&p);
			printf("%lld\n",fastpow(y,z,p));
		}
		if(k == 2)
		{
			scanf("%lld%lld%lld",&y,&z,&p);
			long long x1 = 0,y1 = 0,gcd;
			gcd = exgcd(y,p,x1,y1);
			if(z % gcd == 0)
			{
				long long tmp = p / gcd;
				x1 = ((x1 * z / gcd) % tmp + tmp) % tmp;
				printf("%lld\n",x1);
			}
			else
			{
				printf("Orz, I cannot find x!\n");
			}
		}
		if(k == 3)
		{
			scanf("%lld%lld%lld",&y,&z,&p);
			long long ans = BSGS(y,z,p);
			if(ans == -1)
			{
				printf("Orz, I cannot find x!\n");
			}
			else
			{
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}