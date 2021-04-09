#include<stdio.h>
int gcd(int n,int m)
{
	int r=n%m;
	if(r==0)
		return m;
	else
		return gcd(m,r);
}
int main()
{
	int m,n,ans;
	scanf("%d %d",&n,&m);
	ans=gcd(n,m);
	printf("%d",ans);
	return 0;
}
