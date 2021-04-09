#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int fa[10010];
int val[10010];
int w[10010];
int realcost[10010];
int realval[10010];
int dp[10010];
int findfather(int x)
{
	return fa[x] = fa[x] == x ? fa[x] : findfather(fa[x]);
}
int main()
{
	freopen("buy.in","r",stdin);
	freopen("buy.out","w",stdout);
	int n,m,money;
	scanf("%d%d%d",&n,&m,&money);
	for(int i = 0;i < n;i++)
		scanf("%d%d",&w[i],&val[i]);
	for(int i = 0;i < n;i++)
		fa[i] = i;
	for(int i = 0;i < m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--;
		y--;
		int fatherx,fathery;
		fatherx = findfather(x);
		fathery = findfather(y);
		if(fatherx != fathery)
			fa[fatherx] = fathery,findfather(x);
	}
	for(int i = 0;i < n;i++)
	{
		findfather(i);
		realcost[fa[i]] += w[i];
		realval[fa[i]] += val[i];
	}
	for(int i = 0;i < n;i++)
	{
		if(realcost[i] == 0) continue;
		for(int j = money;j >= realcost[i];j--)
			dp[j] = max(dp[j],dp[j - realcost[i]] + realval[i]);
	}
	printf("%d",dp[money]);
	return 0;
}
