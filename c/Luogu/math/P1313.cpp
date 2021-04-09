#include<stdio.h>
const int MOD = 10007;
int ksm(int a,int b)
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
long long c[1100][1100];
long long calc_c(int a,int b)
{
	if(a == 0 || a == b || b == 0) return 1;
	return c[a][b] = c[b][a] = c[b][a] != 0 ? c[b][a] % MOD : ((c[a - 1][b - 1] == 0 ? calc_c(a - 1,b - 1) % MOD : c[a - 1][b - 1] % MOD) % MOD + (c[a][b - 1] == 0 ? calc_c(a,b - 1) % MOD : c[a][b - 1] % MOD))% MOD;
}
int main()
{
	int a,b,k,n,m;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	c[0][0] = 1;
	printf("%lld",(((calc_c(m,k) % MOD) * ksm(a,n)) % MOD * ksm(b,m)) % MOD);
	return 0;
}