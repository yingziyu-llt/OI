#include<stdio.h>
#include<string.h>
int map[110][110];
int f[110][110];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int m,n;
void dfs(int x,int y,int flag,int val,int c)
{
	if(flag>1) return;
	if(val<f[x][y]) f[x][y]=val;
	else return;
	if(x==m-1&&y==m-1) 
	{
		if(val<f[x][y]) f[x][y]=val;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		if(x+dx[i]>=0&&x+dx[i]<m&&y+dy[i]>=0&&y+dy[i]<m) 
		{
			if(map[x+dx[i]][y+dy[i]]==-1)
				dfs(x+dx[i],y+dy[i],flag+1,val+2,c);
			else if(map[x+dx[i]][y+dy[i]]==c)
				dfs(x+dx[i],y+dy[i],0,val,map[x+dx[i]][y+dy[i]]);
			else if(map[x+dx[i]][y+dy[i]]!=c)
				dfs(x+dx[i],y+dy[i],0,val+1,map[x+dx[i]][y+dy[i]]);
		}
	}
}
int main()
{
	memset(f,127,sizeof(f));
	for(int i=0;i<110;i++)
		for(int j=0;j<110;j++)
			map[i][j]=-1;
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		map[x-1][y-1]=c;
	}
	dfs(0,0,0,0,map[0][0]);
	if(f[m-1][m-1]>2000000)
	{
		printf("-1");
		return 0;
	}
	printf("%d",f[m-1][m-1]);
	return 0;
}
