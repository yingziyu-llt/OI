#include<stdio.h>
int main()
{
	freopen("koopa.in","r",stdin);
	freopen("koopa.out","w",stdout);
	long long n,m;
	while(~scanf("%lld%lld",&n,&m))
	{
		if(m*2*3<n) printf("WIN\n");
		else      printf("LOSE.\n");
	}
	fclose(stdin);
	fclose(stdout);
}
