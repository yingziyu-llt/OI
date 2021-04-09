#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int map[1000][1000];
int main()
{
	freopen("bridge.in","r",stdin);
	freopen("bridge.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i = 0;i < n;i++)
		{
			char s[10010];
			scanf("%s",&s);
			for(int j = 0;j < strlen(s);j++)
			{
				map[i][j] =(s[j] == 'Y' ? 1 : 0x3fffffff);
			}
		}
		for(int k = 0;k < n;k++)
		{
			for(int i = 0;i < n;i++)
			{
				for(int j = 0; j < n;j++)
				{
					if(map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
		int ans = 0;
		for(int i = 0;i < n;i++)
			for(int j = 0;j < i;j++)
				ans = max(ans,map[i][j]);
		printf("%d\n",ans == 0x3fffffff ? -1 : ans * d);
	}
	return 0;
}
