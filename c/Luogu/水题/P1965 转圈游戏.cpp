#include<stdio.h>
int fastpow(int a,int b,int mod)
{
	int x=1;
	int t=a;
	while(b>0)
	{
		if(b&1) x=x*t%mod;
		t=t*t%mod;
	}
	return x;
}
int main()
{
	int n,m,k,x;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	printf("%d",(x%n+m%n*fastpow(10,k,n)%n)%n);
	return 0;
}
