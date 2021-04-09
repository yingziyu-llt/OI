#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[30][30];
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	dp[0][0] = 1;
	for(int i = 1;i <= k;i++)
	{
		for(int j = 0;j < n;j++)
		{
			dp[i][j] = dp[i - 1][(j - 1 + n) % n] + dp[i - 1][(j + 1) % n];
		}
	}
	printf("%d",dp[k][0]);
	return 0;
}