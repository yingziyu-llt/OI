#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;
int dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
bool vis[100][100];
char map[100][100];
int m,n,ans;
void dfs(int x,int y)
{
	for(int i = 0;i < 4;i++)
	{
		int nx = x + dx[i],ny = y + dy[i];
		if(nx >= 0 && ny >= 0 && map[nx][ny] == '.' && !vis[nx][ny])
		{
			ans++;
			vis[nx][ny] = true;
			dfs(nx,ny);
		}
	}
}

int main()
{
	while(1)
	{
		memset(vis,0,sizeof(vis));
		memset(map,0,sizeof(map));
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0) break;
		int fromx = 0,fromy;
		ans = 0;
		for(int i = 0;i < m;i++)
		{
			scanf("%s",map[i]);
			for(int j = 0;j < n;j++)
				if(map[i][j] == '@')
					fromx = i,fromy = j;
		}
		ans = 1;
		dfs(fromx,fromy);
		printf("%d\n",ans);
	}
}