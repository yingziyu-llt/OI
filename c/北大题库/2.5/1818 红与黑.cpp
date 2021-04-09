#include<stdio.h>
#include<string.h>
int a[200][200],ans=0;
int f(int i,int j)
{
	if(a[i][j]!=0)
	{
		ans++;
		a[i][j]=0;
		if(a[i+1][j]!=0)   f(i+1,j);
		if(a[i][j+1]!=0)   f(i,j+1);
		if(a[i][j-1]!=0)   f(i,j-1);
		if(a[i-1][j]!=0)   f(i-1,j);
	} 
} 
int main()
{
	int m,n,x,y;
while(~scanf("%d%d",&m,&n))
{
	if(m==0&&n==0)
		break;
	memset(a,0,sizeof(a));
	ans=0;
	for(int i=1;i<=n;i++)
	{
		char s[100]={0};
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='.') a[i][j]=1;
			if(s[j]=='@') 
			{
				a[i][j]=1;
				x=i;
				y=j;
			}
			if(s[j]=='#')	a[i][j]=0;
		}
	}	
	f(x,y);
	printf("%d\n",ans);
}

	return 0;
}
