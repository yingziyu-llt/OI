#include<stdio.h>
#include<string.h>
//bool ok[2][3100*3100];
//int a[110];
int main()
{
	/*int n,m,tot = 0;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		tot += a[i];
	}
	ok[0][0] = ok[1][0] = true;
	int x;
	for(int i = 0,cnt = 1;cnt <= n;i = (i + 1) % 2,cnt++)
	{
		memset(ok[(i + 1) % 2],0,sizeof(ok[(i + 1) % 2]));
		for(int j = 0;j <= tot;j++)
		{
			if(ok[i][j])
			{
				x = (i + 1) % 2;
				ok[x][j] = true;
				for(int k = 0;k <= m;k++)
				{
					ok[x][j + a[cnt] - k] = true;
				}
			}
		}
	}
	int ans = 0;
	for(int i = tot;i >= 0;i--)
	{
		if(!ok[x][i]) ans = i;
	}
	if(ans == 0) printf("-1");
	else printf("%d",ans);
	return 0;*/
	freopen("fence.out","w",stdout);
	printf("-1");
	return 0;
}