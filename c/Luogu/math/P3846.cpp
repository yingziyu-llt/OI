#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;
long long fastpow(long long a, long long b, long long mod)
{
	long long ans = 1;
	while (b)
	{
		if (b & 1)
			ans = (ans % mod) * (a % mod) % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
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
	long long t, k, y, z, p;
	scanf("%lld%lld%lld", &p, &y, &z);
	long long ans = BSGS(y, z, p);
	if (ans == -1)
	{
		printf("no solution\n");
	}
	else
	{
		printf("%lld\n", ans);
	}
	return 0;
}