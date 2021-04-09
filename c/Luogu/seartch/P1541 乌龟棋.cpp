#include<stdio.h>
#include<algorithm>
using namespace std;
const int N = 370,M = 140;
int value[N],cardNum[5];
int dp[41][41][41][41];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",&value[i]);
	for(int i = 1;i <= m;i++)
	{
		int c;
		scanf("%d",&c);
		cardNum[c]++;
	}
	dp[0][0][0][0] = value[1];
	for(int i = 0;i <= cardNum[1];i++)
	{
		for(int j = 0;j <= cardNum[2];j++)
		{
			for(int k = 0;k <= cardNum[3];k++)
			{
				for(int u = 0;u <= cardNum[4];u++)
				{
					int now = i + j * 2 + k * 3 + u * 4 + 1;
					if(i != 0) dp[i][j][k][u] = max(dp[i][j][k][u],dp[i - 1][j][k][u] + value[now]);
					if(j != 0) dp[i][j][k][u] = max(dp[i][j][k][u],dp[i][j - 1][k][u] + value[now]);
					if(k != 0) dp[i][j][k][u] = max(dp[i][j][k][u],dp[i][j][k - 1][u] + value[now]);
					if(u != 0) dp[i][j][k][u] = max(dp[i][j][k][u],dp[i][j][k][u - 1] + value[now]);
				}
			}
		}
	}
	printf("%d",dp[cardNum[1]][cardNum[2]][cardNum[3]][cardNum[4]]);
	return 0;
}