#include<stdio.h>
int a[200][200],fl[200][200],ans,n;
void Dfs(int x,int y)
{
    fl[x][y]=1;
 	if(x<=0||y<=0||x>n||y>n) return;
 	if(a[x][y]!=0&&a[x][y]!=1&&a[x][y-1]!=2&&a[x][y-1]!=0&&fl[x][y-1]==0) Dfs(x,y-1);
 	if(a[x][y]!=0&&a[x][y]!=2&&a[x][y+1]!=1&&a[x][y+1]!=0&&fl[x][y+1]==0) Dfs(x,y+1);
 	if(a[x][y]!=0&&a[x][y]!=3&&a[x-1][y]!=4&&a[x-1][y]!=0&&fl[x-1][y]==0) Dfs(x-1,y);
 	if(a[x][y]!=0&&a[x][y]!=4&&a[x+1][y]!=3&&a[x+1][y]!=0&&fl[x+1][y]==0) Dfs(x+1,y);
 	return ;
 }
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  if(a[i][j]==10) Dfs(i,j);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	  if(fl[i][j]==0&&a[i][j]!=0) ans++;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 
