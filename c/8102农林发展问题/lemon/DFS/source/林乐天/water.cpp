#include<stdio.h>
int a[110][110];
int map[110][110];
int n,cnt=1;
int dfs(int x,int y)
{
	if(map[x+1][y]==0&&x+1<=n&&a[x+1][y]!=3&&a[x][y]!=4)  {cnt--;map[x+1][y]=1;dfs(x+1,y);}
	if(map[x][y+1]==0&&y+1<=n&&a[x][y+1]!=1&&a[x][y]!=2)  {cnt--;map[x][y+1]=1;dfs(x,y+1);}
	if(map[x-1][y]==0&&x-1>0&&a[x-1][y]!=4&&a[x][y]!=3)  {cnt--;map[x-1][y]=1;dfs(x-1,y);}
	if(map[x][y-1]==0&&y-1>0&&a[x][y-1]!=2&&a[x][y]!=1)  {cnt--;map[x][y-1]=1;dfs(x,y-1);}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout); 
	int ai,aj;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==10)
			{
				ai=i;
				aj=j;
			}
			else if(a[i][j]!=10&&a[i][j]!=0) cnt++;
			else if(a[i][j]==0) map[i][j]=1;
		}
	dfs(ai,aj);
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
} 
