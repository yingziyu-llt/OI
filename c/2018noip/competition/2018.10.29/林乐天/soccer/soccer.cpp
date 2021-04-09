#include<stdio.h>
#include<string.h>
int ans[100010];
int main()
{
	freopen("soccer.in","r",stdin);
	freopen("soccer.out","w",stdout);
	char c;
	int NUM;
	scanf("%d",&NUM);
	while(NUM--)
	{
		memset(ans,0,sizeof(ans));
		int n;
		scanf("%d",&n);
		getchar();
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				c = getchar();
				if(c == 'W')     ans[i] += 3;
				else if(c == 'D')
				{
					ans[i] += 1;
					ans[j] += 1;
				}
				else if(c == 'L') ans[j] += 3;
			}
			c = getchar();
		}
		for(int i = 0;i < n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
}