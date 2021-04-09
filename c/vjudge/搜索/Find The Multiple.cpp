#include<stdio.h>
#include<algorithm>
using namespace std;
int ans[10010];
int n;
int dfs(int k,int c)
{
	if(k == 0)
	{
		return c;
	}
	if(c > 20) return 0;
	ans[c + 1] = 0;
	int len = dfs((k * 10) % n,c + 1);
	if(len)
		return len;
	ans[c + 1] = 1;
	len = dfs((k * 10 + 1) % n,c + 1);
	if(len)
		return len;
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n == 0) return 0;
		int len;
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		ans[1] = 1;
		len = dfs(1,1);
		for(int i = 1;i <= len;i++)
			printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}