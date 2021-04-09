#include<stdio.h>
#include<string.h>
int d[100];
char map[100][100];
int ans;
int n,k;
void dfs(int x,int y)
{
	for(int i=1;i<=n;i++)
	{
		if(map[x][i]=='#'&&d[i]==0)
		{
			if(y==1) ans++;
			else
			{
				for(int j=x;j<=n-y+1;j++)
				{
					d[i]=1;dfs(j+1,y-1);d[i]=0;
				}
			}
		}
	}
}
int main()
{
	while(1)
	{
		ans=0;
		memset(map,0,sizeof(map));
		memset(d,0,sizeof(d)); 
		scanf("%d %d",&n,&k);
		if(n==-1&&k==-1) break;
		for(int i=1;i<=n;i++)
			scanf("%s",map[i]+1); 
		for(int i=1;i<=n-k+1;i++)
			dfs(i,k);
		printf("%d\n",ans);
	}
}
