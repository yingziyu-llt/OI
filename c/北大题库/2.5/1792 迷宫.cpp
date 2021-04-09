#include<stdio.h>
#include<string.h>
int a[105][105];
int z,y;
bool dfs(int i,int j)
{
	bool x=false;
	if(i==z&&j==y&&a[i][j]!=0)
	{
		return true;
	}
	if(a[i][j]!=0)
	{
		a[i][j]=0;
		if(a[i+1][j]!=0) x=x|dfs(i+1,j);
		if(x) return true;
		if(a[i][j+1]!=0) x=x|dfs(i,j+1);
		if(x) return true;
		if(a[i-1][j]!=0) x=x|dfs(i-1,j);
		if(x) return true;
		if(a[i][j-1]!=0) x=x|dfs(i,j-1);
		if(x) return true;
	}
	return x;
}
int main()
{
	int n,t;
	scanf("%d",&t);
	for(int i1=0;i1<t;i1++)
	{
		int i,j;
		memset(a,0,sizeof(a));
		int c=0,d=0;
		scanf("%d",&n);
		char l[110]={0};
		for(i=1;i<=n;i++)
		{
			scanf("%s",l+1);
			for(j=1;j<=n;j++)
			{
				if(l[j]=='.') a[i][j]=1;
			}
		}
		scanf("%d%d%d%d",&c,&d,&z,&y);
		c++;d++;z++;y++;
		if(dfs(c,d)==true) 	printf("YES\n");
		else                printf("NO\n");
	}
	return 0;
} 
