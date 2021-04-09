#include<stdio.h>
#include<algorithm>
using namespace std;
int f[1001][1001];
int main()
{
	int m,n;
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=10;j++)
		{
			f[i][j]=i;
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=1;k<=10;k++)
			{
				f[i][j]=min(f[i][j],max(f[i-k][j],f[k-1][j-1])+1);
			}
		}
	}
	while (scanf("%d%d",&m,&n)!=EOF)
		printf("%d\n",f[m][n]);
	return 0;
} 
