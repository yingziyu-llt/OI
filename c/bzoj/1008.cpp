#include<stdio.h>
const int MOD = 100003;
long long ksm(long long a,long long b)
{
	long long ans = 1;
	while(b)
	{
		if(b & 1)
			ans = ((ans % MOD) * (a % MOD) )% MOD;
		a = ((a % MOD) * (a % MOD)) % MOD;
		b >>= 1;
	}
	return ans;
}
int main()
{
	long long m,n;
	scanf("%lld%lld",&m,&n);
	printf("%lld",(ksm(m,n) - (m * ksm(m - 1,n - 1)) % MOD + MOD) % MOD);
	return 0;
}