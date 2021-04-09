#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int n,i,j,cnt=0,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},a[105][105],b[105][105];
bool bo[105][105];
void dfs(int x,int y)
{
	bo[x][y]=1;
 	if(x<=0||y<=0||x>n||y>n) return;
 	if(a[x][y]!=0&&a[x][y]!=1&&a[x][y-1]!=2&&a[x][y-1]!=0&&bo[x][y-1]==0) dfs(x,y-1);
 	if(a[x][y]!=0&&a[x][y]!=2&&a[x][y+1]!=1&&a[x][y+1]!=0&&bo[x][y+1]==0) dfs(x,y+1);
 	if(a[x][y]!=0&&a[x][y]!=3&&a[x-1][y]!=4&&a[x-1][y]!=0&&bo[x-1][y]==0) dfs(x-1,y);
 	if(a[x][y]!=0&&a[x][y]!=4&&a[x+1][y]!=3&&a[x+1][y]!=0&&bo[x+1][y]==0) dfs(x+1,y);
}
int main()
{
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
			if(bo[i][j]==0&&a[i][j]!=0)cnt++;
	printf("%d",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
