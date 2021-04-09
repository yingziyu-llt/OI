#include<stdio.h>
int main()
{
	int m,n;
	int a[110][110]={0};
	scanf("%d %d",&m,&n);
	scanf("%*c");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char tmp;
			scanf("%c",&tmp);
			if(tmp=='*')
				a[i][j]=-1;
		}
		scanf("%*c");
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==-1) continue;
			if(a[i-1][j+1]==-1) a[i][j]++;
			if(a[i][j+1]==-1)   a[i][j]++;
			if(a[i+1][j+1]==-1) a[i][j]++;
			if(a[i-1][j]==-1)   a[i][j]++;
			if(a[i+1][j]==-1)   a[i][j]++;
			if(a[i-1][j-1]==-1) a[i][j]++;
			if(a[i][j-1]==-1)   a[i][j]++;
			if(a[i+1][j-1]==-1) a[i][j]++;
		}
	} 
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==-1) printf("*");
			else            printf("%d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
