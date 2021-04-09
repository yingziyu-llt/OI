#include <stdio.h>
#include <string.h>
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char a[10][15][15];
int bk,m;
void dfs(int x,int y)
{
	int i;
	if(a[1][x][y]=='@')
	{
		bk=1;
		return ;
	}
	if(a[1][x][y]=='.')
	{
		a[1][x][y]='#';
		for(i=0;i<=3;i++)
			if(a[1][x+dx[i]][y+dy[i]]=='.'||a[1][x+dx[i]][y+dy[i]]=='@')
				dfs(x+dx[i],y+dy[i]);
	}
}

void dfss(int k,int x,int y)
{
	int i;
	if(a[k][x][y]=='@')
	{
		bk=1;
		return ;
	}
	if(a[k][x][y]=='.')
	{
		a[k][x][y]='#';
		for(i=0;i<=3;i++)
			if(a[k][x+dx[i]][y+dy[i]]=='.'||a[k][x+dx[i]][y+dy[i]]=='@')
				dfss(k,x+dx[i],y+dy[i]);
		for(i=1;i<=m;i++)
			if(k!=i)
			{
				if(a[i][x][y]=='.'||a[i][x][y]=='@')
					dfss(i,x,y);
			}
	}
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	int n,i,j;
	while(scanf("%d%d",&m,&n)&&m&&n)
	{
		memset(a,0,sizeof(a));
		if(m==1)
		{
			bk=0;
			scanf("%s",a[1][1]+1);
			for(i=1;i<=n;i++)
			{
				if(a[1][1][i]=='#')break;
				else if(a[1][1][i]=='@')
				{
					bk=1;
					break;
				}
			}
			if(bk==1)printf("YES\n");
			else   	 printf("No\n");
		}
		if(m==2)
		{
			bk=0;
			for(i=1;i<=n;i++)
				scanf("%s",a[1][i]+1);
			dfs(1,1);
			if(bk==0)printf("No\n");
			else     printf("YES\n");
		}
		if(m>=3)
		{
			bk=0;
			for(i=1;i<=m;i++)
				for(j=1;j<=n;j++)
					scanf("%s",a[i][j]+1);
			dfss(1,1,1);
			if(bk==0)printf("No\n");
			else     printf("YES\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
