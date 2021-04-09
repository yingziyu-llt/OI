#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[200];
bool dp[50000];
int main()
{
	int T;
	scanf("%d", &T);
	for (int _i = 0; _i < T; _i++)
	{
		int n,maxn = 0,minn = 0x7fffffff;
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			maxn = max(a[i],maxn);
			minn = min(a[i],minn);
		}
		sort(a, a + n);
		int m = 0;
		int k = 0;
		for (int i = 1; i <= maxn; i++)
		{
			if (i == a[k] && dp[i]) k++;
			else if (i == a[k] && !dp[i])
			{
				dp[i] = true;
				m++;
				k++;
			}
			if (!dp[i])
				continue;
			for (int j = minn; j <= maxn; j++)
			{
				if (dp[j])
				{
					dp[i + j] = true;
				}
			}
		}
		printf("%d", m);
	}
	return 0;
}