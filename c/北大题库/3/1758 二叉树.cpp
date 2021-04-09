#include<stdio.h>
int x[64],y[64];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int maxn=a>b?a:b;
	x[0]=a;
	y[0]=b;
	for(int i=1;i<=maxn;i++)
	{
		x[i]=a/2;
		y[i]=b/2;
		a/=2;
		b/=2;
	}
	for(int i=0;x[i]!=0;i++)
	{
		for(int j=0;y[j]!=0;j++)
		{
			if(x[i]==y[j])
			{
				printf("%d",x[i]);
				return 0;
			}
		}
	}
} 
