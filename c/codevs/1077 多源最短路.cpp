#include<stdio.h>
#include<string.h>
int f[101][101];
int main()
{
	int n; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
		}
		
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(f[i][j]>f[k][j]+f[i][k])
				{
					f[i][j]=f[i][k]+f[k][j];				
				}
			} 
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",f[x][y]);
	}
	return 0;
}
