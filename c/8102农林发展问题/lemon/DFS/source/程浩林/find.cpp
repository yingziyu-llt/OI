#include<stdio.h>
#include<string.h>
int i=0,n,m,p,ax,ay,bx,by,ans[100]={};
char a[101][101],b[101][101];
void Try(int i,int j)
{
	if(a[i][j]=='.')
	{
		a[i][j]='#';
		if(i==ax&&j==ay)p=1;
		if(a[i+1][j]=='.')
			Try(i+1,j);
		if(a[i][j+1]=='.')
			Try(i,j+1);
		if(a[i-1][j]=='.')
			Try(i-1,j);
		if(a[i][j-1]=='.')
			Try(i,j-1);
	}	
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout); 
	while(scanf("%d%d",&n,&m)&&n!=0&&m!=0)
	{
		i++;p=0;ax=0;ay=0;
		memset(a,0,sizeof(a));//÷√¡„ 
		while(m--)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%s",&b[j]);
				for(int k=1;k<=n;k++)
				{
					if(b[j][k]=='@')				{ax=j;ay=k;a[j][k]='.';}
					if(b[j][k]=='.')				{a[j][k]='.';}
					if(b[j][k]=='#'&&a[j][k]!='.')  {a[j][k]='#';}
				}
				scanf("\n");
			}
			if(ax==0&&ay==0)
			{
				ans[i]=0;
				continue;
			}
			if(a[1][1]=='#')
			{
				ans[i]=0;
				continue;
			}
			Try(1,1);
			ans[i]=p;
		}
	}
	for(int j=1;j<=i;j++)
		if(ans[i]==1)printf("YES\n");
		else         printf("NO\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

