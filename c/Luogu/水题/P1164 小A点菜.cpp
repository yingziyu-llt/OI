#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[10010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	dp[0] = 1;
	for(int i = 0;i < n;i++)
	{
		int val;
		scanf("%d",&val);
		for(int j = m;j >= val;j--)
		{
			dp[j] = dp[j] + dp[j - val];
		}
	}
	printf("%d",dp[m]);
	return 0;
} 
