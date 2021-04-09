#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int dp[200000];
int a[200000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)
		dp[i] = a[i];
	for(int i = 1;i < n;i++)
		dp[i] = max(dp[i - 1] + a[i],dp[i]);
	int maxn = -INF;
	for(int i = 0;i < n;i++)
		maxn = max(maxn,dp[i]);
	printf("%d",maxn);
	return 0;
}