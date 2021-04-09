#include <stdio.h>
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool pp[105][105];
int map[105][105],b[105][105];
void dfs(int x,int y,int t)
{
	int i;
	pp[x][y]=1;
	for(i=0;i<=3;i++)
	{
		if(map[x+dx[i]][y+dy[i]]==0)continue;
		else if(i==0&&map[x][y+1]!=1&&map[x][y]!=2)
			{
				map[x][y]=0;
				dfs(x,y+1,t);
				map[x][y]=b[x][y];
			}
		else if(i==1&&map[x][y-1]!=2&&map[x][y]!=1)
			{
				map[x][y]=0;
				dfs(x,y-1,t);
				map[x][y]=b[x][y];
			}
		else if(i==2&&map[x+1][y]!=3&&map[x][y]!=4)
			{
				map[x][y]=0;
				dfs(x+1,y,t);
				map[x][y]=b[x][y];
			}
		else if(i==3&&map[x-1][y]!=4&&map[x][y]!=3)
			{
				map[x][y]=0;
				dfs(x-1,y,t);
				map[x][y]=b[x][y];
			}
	}
}
int main()
{
	int n,i,j,ans=0;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
			b[i][j]=map[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(map[i][j]==10)
			{
				map[i][j]=5;
				dfs(i,j,0);
			}
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(pp[i][j]==0&&map[i][j]!=0)ans++;
	printf("%d",ans);
	return 0;
}
