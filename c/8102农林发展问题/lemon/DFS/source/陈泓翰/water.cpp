#include <stdio.h>
#include <math.h>
#include <string.h>
bool pd[1206][1206];
int a[1206][1206],b[1206][1206];
int nca[4]={0,0,1,-1};
int byz[4]={1,-1,0,0};
void dfs(int x,int y,int t)
{
	int i;
	pd[x][y]=1;
	for(i=0;i<=3;i++)
	{
	if(a[x+nca[i]][y+byz[i]]==0)
	continue;
	if(i==0)
	if(a[x][y+1]!=1&&a[x][y]!=2)
	{
	a[x][y]=0;
	dfs(x,y+1,t);
	a[x][y]=b[x][y];
	}  
	if(i==1)
	if(a[x][y-1]!=2&&a[x][y]!=1)
	{
	a[x][y]=0;
	dfs(x,y-1,t);
	a[x][y]=b[x][y];
	}
    if(i==2)
	if(a[x+1][y]!=3&&a[x][y]!=4)
	{
	a[x][y]=0;
	dfs(x+1,y,t);
	a[x][y]=b[x][y];
	}
	if(i==3)
	if(a[x-1][y]!=4&&a[x][y]!=3)
	{
	a[x][y]=0;
	dfs(x-1,y,t);
    a[x][y]=b[x][y];
    }
	}
}
int main()
{
	int Arturia=0,n,i,j;
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
	scanf("%d",&a[i][j]);
	b[i][j]=a[i][j];
	}
	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	{
	if(a[i][j]==10)
	{
	a[i][j]=5;
	dfs(i,j,0);
	}
	}
	for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
	if(pd[i][j]==0&&a[i][j]!=0)
	Arturia++;
	printf("%d",Arturia);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
