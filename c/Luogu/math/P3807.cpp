#include<stdio.h>
#include<string.h>//逆元 a^p-2
#include<algorithm>
using namespace std;
long long MOD;
int factans[110000];
long long ksm(long long a,long long b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}
long long calc_c(long long n, long long m) //组合数C(n, m) % p
{
	if (m > n)
		return 0;
	long long up = 1, down = 1; //分子分母;
	for (int i = n - m + 1; i <= n; i++)
		up = up * i % MOD;
	for (int i = 1; i <= m; i++)
		down = down * i % MOD;
	return up * ksm(down, MOD - 2) % MOD;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int _i = 0;_i < T;_i++)
	{
		int m,n;
		scanf("%d%d%lld",&n,&m,&MOD);
		n += m;
		n %= MOD;
		int mi[200],ni[200];
		memset(mi,0,sizeof(mi));
		memset(ni,0,sizeof(ni));
		int i1 = 0;
		while(m)
		{
			mi[i1] = m % MOD;
			m /= MOD;
			i1++;
		}
		int j1 = 0;
		while(n)
		{
			ni[j1] = n % MOD;
			n /= MOD;
			j1++;
		}
		long long ans = 1;
		for(int i = 0;i < 200;i++)
		{
			ans = ans * calc_c(max(mi[i],ni[i]),min(mi[i],ni[i])) % MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
