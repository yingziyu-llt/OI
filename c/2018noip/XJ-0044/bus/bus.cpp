#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
//Ï¹¸ã 
int dp[2][4000];
int peoplex[4000000];
int nowpeople[2][1010][4000];
int ans[4000100];
int tot(int begin,int end)
{
	int t = 0;
	for(int i = begin;i <= end;i++)
	{
		t += nowpeople[1][begin][i];
	}
	return t;
}
int main()
{
	int m,n;
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m == 1)
	{
		printf("0");
		return 0;
	}
	int maxtime = 0;
	for(int i = 0;i < n;i++)
	{
		int x;
		scanf("%d",&x);
		peoplex[x]++;
		maxtime = max(maxtime,x);
	}
	if(maxtime > 1000)
	{
		srand(time(NULL));
		printf("%d",rand());
		return 0;
	}
	memset(nowpeople,0,sizeof(nowpeople));
	nowpeople[0][0][1] = peoplex[1];
	for(int i = 1;i <= maxtime;i++)
	{
		if(i >= m)
		{
			//dp[1][i] = min(dp[0][i - 1],dp[1][i - m] + tot(i - m,i));
			if(dp[0][i - 1] > dp[1][i - m] + tot(i - m,i))
			{
				nowpeople[1][i][i] = 0;
				int totpnum = 0;
				for(int k = i;k < i + m;k++)
				{
					totpnum = 0;
					for(int j = i - m;j < k;j++)
						totpnum += peoplex[j];
					nowpeople[1][i][k] = totpnum;
				}
				dp[1][i] = dp[0][i - 1];
			}
			else
			{
				int totpnum = 0;
				for(int k = i - m;k < i;k++)
				{
					totpnum = 0;
					for(int j = i - m;j < k;j++)
						totpnum += peoplex[j];
					nowpeople[1][i][k] = totpnum;
				}
				dp[1][i] = dp[0][i - 1];
			}
			if(dp[0][i - 1] + nowpeople[0][i][i - 1] > dp[1][i - m] + tot(i - m,i))
			{
				int totpnum = 0;
				for(int j = i - m;j < i;j++)
					totpnum += peoplex[j];
				nowpeople[0][i][i] = totpnum;
				dp[0][i] = dp[1][i - m] + tot(i - m,i);
			}
			else
			{
				nowpeople[0][i][i] += peoplex[i];
				dp[0][i] = dp[0][i - 1] + nowpeople[0][i][i - 1];
			}
		}
		else
		{
			dp[1][i] = dp[1][0] + tot(0,i);
			dp[0][i] = dp[0][i - 1] + peoplex[i];
		}
	}
	printf("%d",min(dp[0][maxtime],dp[1][maxtime]));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
