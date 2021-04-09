#include<stdio.h>
int main()
{
	freopen("horrible.in","r",stdin);
	freopen("horrible.out","w",stdout);
	int m,n;
	scanf("%d",&m);
	int ans = 1;
	for(int i = 1;i <= m;i++)
	{
		ans = ans * i % 998244353;
	}
	printf("%d",ans);
	return 0;
}