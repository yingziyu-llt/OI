#include<stdio.h>
int a[64][64];
int tob(int x,int a[64])
{
	int i=0;
	while(x!=0)
	{
		a[i]=x%2;
		x/=2;
		i++;
	}
	a[i]=-1;
}
int pd(int x,int i)
{
	int c[100],j=0;
	while(a[i][j]!=-1)
	{
		if(a[i][j]==1)
		{
			c[i]
		}
	}
}
