#include<stdio.h>
int f[10000];
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		int w,c;
		scanf("%d%d",&w,&c);
		for(j=n;j>=w;j--)
		{
			if(f[j-w]+c>f[j]) f[j]=f[j-w]+c;
		}
	}
	printf("%d",f[n]);
} 
/*10 4
2 1
3 3
4 5
7 9

*/
