#include<stdio.h>
const long long Mod = 1000000007;
long long ksm(long long a,long long k)
{
	long long ans = 1;
	while(k)
	{
		if(k & 1) 
			ans = (ans * a) % Mod;
		a = a * a % Mod;
		k >>= 1;
	}
	return ans % Mod;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n;
	scanf("%d",&n);
	printf("%d",(ksm(3,n + 1) - 1) / 2);
	return 0;
}
