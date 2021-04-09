#include <stdio.h>
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool pd[105][105];
int a[105][105],b[105][105];
void dfs(int x,int y)
{
	int i;
	pd[x][y]=1;
	for(i=0;i<=3;i++)
	{
		if(a[x+dx[i]][y+dy[i]]==0)continue;
		if(i==0)
			if(b[x][y+1]!=1&&b[x][y]!=2)
			{
				a[x][y]=0;
				dfs(x,y+1);
			}//1 zuo  
		if(i==1)
			if(b[x][y-1]!=2&&b[x][y]!=1)
			{
				a[x][y]=0;
				dfs(x,y-1);//2 you
			}
		if(i==2)
			if(b[x+1][y]!=3&&b[x][y]!=4)
			{
				a[x][y]=0;
				dfs(x+1,y);//3 shang
			}
		if(i==3)
			if(b[x-1][y]!=4&&b[x][y]!=3)
			{
				a[x][y]=0;
				dfs(x-1,y);//4 xia
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
			scanf("%d",&a[i][j]);
			b[i][j]=a[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==10)
			{
				a[i][j]=5;
				dfs(i,j);
			}
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(pd[i][j]==0&&b[i][j]!=0)ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
