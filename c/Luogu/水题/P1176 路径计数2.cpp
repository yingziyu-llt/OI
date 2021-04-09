#include <stdio.h>
int dp[10000][10000];
int main()
{
	int n;
	int m = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		dp[x - 1][y - 1] = -1;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > 0 && dp[i][j] != -1 && dp[i - 1][j] != -1)
				dp[i][j] += dp[i - 1][j];
			dp[i][j] %= 100003;
			if (j > 0 && dp[i][j] != -1 && dp[i][j - 1] != -1)
				dp[i][j] += dp[i][j - 1];
			dp[i][j] %= 100003;
		}
	}
	printf("%d", dp[n - 1][n - 1] == -1 ? 0 : dp[n - 1][n - 1]);
	return 0;
}