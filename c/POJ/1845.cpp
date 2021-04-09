#include<stdio.h>
const int MOD = 9901;

int ksm(int a,int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans % MOD) * (a % MOD) % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int ans = 1;
	int a,b;
	scanf("%d %d",&a,&b);
	for(int i = 2;i <= a;i++)
	{
		long long ai = 0;
		for(ai = 0;;ai++)
		{
			if(a % i != 0)
				break;
			a /= i;
		}
		ai *= b;
		int tmp = 0;
		tmp = 1 * ((ksm(i,ai + 1) - 1 + MOD) % MOD) * (i - 1) % MOD;
		ans = ((ans % MOD) * (tmp % MOD)) % MOD;
	}
	printf("%d",ans % MOD);
	return 0;
}