#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[1001][1001];
int h[1001],x[1001];
int main()
{
	int n,m,kk;
	scanf("%d%d%d",&n,&m,&kk);
	for(int i=0;i<kk;i++)
		scanf("%d%d",&x[i],&h[i]);
	for(int i=0;i<kk;i++)
	{
		
		for(int j=m;j>=h[i];j--)
		{
			for(int k=n;k>=x[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-h[i]][k-x[i]]+1);
			}
		}
	}
	printf("%d ",dp[m][n]);
	for(int i=0;i<=m;i++)
	{
		if(dp[i][n]==dp[m][n])
		{
			printf("%d",m-i);
			break;
		}
	}
}
