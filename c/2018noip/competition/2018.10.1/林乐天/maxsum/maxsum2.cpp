#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001], dp[1001];
inline int qh(int n)
{
	int i, s = 0, l;
	for (i = 1; i <= n / 2; i++)
	{
		if (n % i == 0)
			s += i;
	}
	return s;
}
int main()
{
	freopen("maxsum.in","r",stdin);
	freopen("maxsum1.out","w",stdout);
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		a[i] = qh(i);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = i; j <= n; j++)
		{
			//printf("dp[%d]=max(dp[%d],dp[%d]+a[%d])=%d\n",j,j,j-i,i,dp[j]);
			dp[j] = max(dp[j], dp[j - i] + a[i]);
		}
		// printf("\n");
	}
	printf("%d", dp[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
