#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[11000];
int main()
{
	int v,n,c;
	scanf("%d%d%d",&v,&n,&c);
	for(int _i = 0;_i < n;_i++)
	{
		int w,val;
		scanf("%d%d",&val,&w);
		for(int i = c;i >=w;i--)
			dp[i] = max(dp[i - w] + val,dp[i]);
	}
	if(dp[c] < v) printf("Impossible");
	else
	{
		for(int i = 0; i <= c;i++)
		{
			if(dp[i] >= v) 
			{
				printf("%d",c - i);
				return 0;
			}
		}
	}
}