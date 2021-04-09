#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std; 
int c[100],map[100][100];
int dx[] = {0,1,0,-1,0},dy[] = {0,0,1,0,-1};
int n,m,k;
bool flag;
void dfs(int x,int y,int rest)
{
	for(int i = 1;i <= k;i++)
	{
		if(c[i] > (rest + 1) / 2)
			return;
	}
	if(rest == 0)
	{
		flag = true;
		return ;
	}
	for(int i = 1;i <= 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		for(int j = 1;j <= k;j++)
		if(nx > 0 && ny > 0 && nx <= m && ny <= n && c[j] && map[nx][ny] == 0 && map[nx - 1][ny] != j && map[nx][ny - 1] != j && map[nx + 1][ny] != j&& map[nx][ny + 1] != j)
		{
			c[j]--;
			map[nx][ny] = j;
			dfs(nx,ny,rest - 1);
			if(flag) return ;
			map[nx][ny] = 0;
			c[j]++;
		} 
	}
}

int main()
{
	//freopen("out.txt","w",stdout);
	int T,cnt = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&m,&n,&k);
		for(int i = 1;i <= k;i++)
			scanf("%d",&c[i]);
		flag = 0;
		memset(map,0,sizeof(map));
		for(int i = 1;i <= k;i++)
		{
			c[i]--;
			map[1][1] = i;
			dfs(1,1,n * m - 1);
			if(flag)
				break;
			c[i]++;
		}
		printf("Case #%d:\n",cnt);
		cnt++;
		if(flag)
		{
			printf("YES\n");
			for(int i = 1;i <= m;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					printf("%d ",map[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}