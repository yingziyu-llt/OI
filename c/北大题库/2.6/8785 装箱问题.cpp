#include<stdio.h>
int f[30000];
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		int w,c;
		scanf("%d",&w);
		for(j=n;j>=w;j--)
		{
			if(f[j-w]+w>f[j]) f[j]=f[j-w]+w;
		}
	}
	printf("%d",n-f[n]);
} 
