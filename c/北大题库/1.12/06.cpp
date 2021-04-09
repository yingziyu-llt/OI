#include<stdio.h>
int a[110000][100],b[11000][100],c[10010],ans;
int i,j,m,n,t,x,s;
int input(a[][],b[][],c[][],&m,&n,&t)
{
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			scanf("%d%d",&a[i][j],&b[i][j]);
			if(a[i][j]==1) c[i]++;
		}
	}
	scanf("%d",&t);
}
int work(a[][],b[][],&ans)
{
	for(i=0;i<n;i++)
	{
		ans=(ans+b[i][t])%20123;
		x=(b[i][t]-1)%c[i]+1;
		if(a[i][t]==1) s=1;else s=0;
		while(s<x)
		{
			if(t==m-1)  t=0;
			else        t++;
			if(a[i][t]==1)
				s++;
		}
	}
}
int main()
{
	input();
	work();
	printf("%d",ans);
	return 0;
}

