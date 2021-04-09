#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct date
{
	int n;
	bool zl[1010];
} dp[1010];
bool zl[1010];
int find(int n)
{
	int i;
	int ans = 0;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i != n / i)
				ans += i + n / i;
			else
				ans += i;
		}
	}
	ans += 1;
	zl[n] = true;
	return ans;
}
bool pd(int n, int m)
{
	for (int i = 0; i <= 1010; i++)
		if (dp[n].zl[i] && dp[m].zl[i])
			return false;
	return true;
}
void copy(int n, int m)
{
	for (int i = 0; i < 1010; i++)
	{
		dp[n].zl[i] = dp[n].zl[i] || dp[m].zl[i];
	}
}
int main()
{
	int n, x;
	//freopen("maxsum.in", "r", stdin);
	//freopen("maxsum.out", "w", stdout);
	scanf("%d", &n);
	dp[0].n = 0;
	dp[0].zl[0] = true;
	dp[1].n = 0;
	dp[1].zl[1] = true;
	if (n == 1 || n == 0)
	{
		printf("0");
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		memset(zl, 0, sizeof(zl));
		x = find(i);
		memset(dp[i].zl, 0, sizeof(dp[i].zl));
		for (int j = 1; j < i; j++)
		{
			if (dp[i].n < dp[j].n + dp[i - j].n)
			{
				if (pd(j, i - j))
				{
					memset(dp[i].zl, 0, sizeof(dp[i].zl));
					dp[i].n = dp[j].n + dp[i - j].n;
					copy(i, j);
					copy(i, i - j);
				}
			}
			if (dp[i].n < x)
			{
				dp[i].n = x;
				for (int j = 0; j < 1010; j++)
					dp[i].zl[j] = zl[j];
			}
		}
	}
	printf("%d", dp[n].n);
	return 0;
}