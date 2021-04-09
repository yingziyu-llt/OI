#include<stdio.h>
int main()
{
	int n,k,ans=0;
	scanf("%d %d",&n,&k);
	ans+=n;
	while(n>=k)
	{
		n-=k;
		ans++;
		n++;
	}
	printf("%d",ans);
	return 0;
}
